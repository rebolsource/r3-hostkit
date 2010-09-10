/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: OS API function library called by REBOL interpreter
**  Build: A95
**  Date:  27-Nov-2009
**  File:  host-lib.c
**  Author: Carl Sassenrath
**  Purpose: 
**      This module provides the functions that REBOL calls
**      to interface to the native (host) operating system.
**      REBOL accesses these functions through the structure
**      defined in host-lib.h (auto-generated, do not modify).
**
************************************************************************
**
**  NOTE to PROGRAMMERS:
**
**    1. Keep code clear and simple.
**    2. Document unusual code, reasoning, or gotchas.
**    3. Use same style for code, vars, indent(4), comments, etc.
**    4. Keep in mind Linux, OS X, BSD, big/little endian CPUs.
**    5. Test everything, then test it again.
**
***********************************************************************/

/* WARNING:
**     The function declarations here cannot be modified without
**     also modifying those found in the other OS host-lib files!
**     Do not even modify the argument names.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <dlfcn.h>

#ifndef timeval // for older systems
#include <sys/time.h>
#endif

#include "reb-host.h"
#include "host-lib.h"

// Semaphore lock to sync sub-task launch:
static void *Task_Ready;

#ifndef PATH_MAX
#define PATH_MAX 4096  // generally lacking in Posix
#endif


/***********************************************************************
**
**	Local Functions
**
***********************************************************************/

/***********************************************************************
**
*/	static int Get_Timezone(struct tm *local_tm)
/*
**		Get the time zone in minutes from GMT.
**		NOT consistently supported in Posix OSes!
**		We have to use a few different methods.
**
***********************************************************************/
{
#ifdef HAS_SMART_TIMEZONE
	time_t rightnow;
	time(&rightnow);
	return (int)difftime(mktime(localtime(&rightnow)), mktime(gmtime(&rightnow))) / 60;
#else
	struct tm tm2;
	time_t rightnow;
	time(&rightnow);
	tm2 = *localtime(&rightnow);
	tm2.tm_isdst=0;
	return (int)difftime(mktime(&tm2), mktime(gmtime(&rightnow))) / 60;
#endif
//	 return local_tm->tm_gmtoff / 60;  // makes the most sense, but no longer used
}


/***********************************************************************
**
*/	void Convert_Date(time_t *stime, REBOL_DAT *dat, long zone)
/*
**		Convert local format of system time into standard date
**		and time structure (for date/time and file timestamps).
**
***********************************************************************/
{
	struct tm *time;

	CLEARS(dat);

	time = gmtime(stime);

	dat->year  = time->tm_year + 1900;
	dat->month = time->tm_mon + 1;
	dat->day   = time->tm_mday;
	dat->time  = time->tm_hour * 3600 + time->tm_min * 60 + time->tm_sec;
	dat->nano  = 0;
	dat->zone  = Get_Timezone(time);
}


/***********************************************************************
**
**	OS Library Functions
**
***********************************************************************/

/***********************************************************************
**
*/	void *OS_Make(size_t size)
/*
**		Allocate memory of given size.
**
**		This is necessary because some environments may use their
**		own specific memory allocation (e.g. private heaps).
**
***********************************************************************/
{
	return malloc(size);
}


/***********************************************************************
**
*/	void OS_Free(void *mem)
/*
**		Free memory allocated in this OS environment. (See OS_Make)
**
***********************************************************************/
{
	free(mem);
}


/***********************************************************************
**
*/	void OS_Exit(int code)
/*
**		Called in cases where REBOL needs to quit immediately
**		without returning from the main() function.
**
***********************************************************************/
{
	OS_Call_Device(RDI_STDIO, RDC_CLOSE); // close echo
	exit(code);
}


/***********************************************************************
**
*/	void OS_Crash(const REBCHR *title, const REBCHR *content)
/*
**		Tell user that REBOL has crashed. This function must use
**		the most obvious and reliable method of displaying the
**		crash message.
**
**		If the title is NULL, then REBOL is running in a server mode.
**		In that case, we do not want the crash message to appear on
**		the screen, because the system may be unattended.
**
**		On some systems, the error may be recorded in the system log.
**
***********************************************************************/
{
	// Echo crash message if echo file is open:
	///PUTE(content);
	OS_Call_Device(RDI_STDIO, RDC_CLOSE); // close echo

	// A title tells us we should alert the user:
	if (title) {
		fputs(title, stderr);
		fputs(":\n", stderr);
	}
	fputs(content, stderr);
	fputs("\n\n", stderr);
	exit(100);
}


/***********************************************************************
**
*/	REBCHR *OS_Form_Error(int errnum, REBCHR *str, int len)
/*
**		Translate OS error into a string. The str is the string
**		buffer and the len is the length of the buffer.
**
***********************************************************************/
{
	strerror_r(errnum, str, len);
	return str;
}


/***********************************************************************
**
*/	BOOL OS_Get_Boot_Path(REBCHR *name)
/*
**		Used to determine the program file path for REBOL.
**		This is the path stored in system->options->boot and
**		it is used for finding default boot files.
**
***********************************************************************/
{
	return FALSE; // not yet used
}


/***********************************************************************
**
*/	REBCHR *OS_Get_Locale(int what)
/*
**		Used to obtain locale information from the system.
**		The returned value must be freed with OS_FREE_MEM.
**
***********************************************************************/
{
	return 0; // not yet used
}


/***********************************************************************
**
*/	REBCHR *OS_Get_Env(REBCHR *var, int mode)
/*
**		Get a value from the environment.
**		(Mode will allow for unicode later.)
**		Resturns string for success or zero if missing.
**		Return string should be copied not stored or changed.
**
***********************************************************************/
{
	return getenv(var);
}


/***********************************************************************
**
*/	int OS_Set_Env(REBCHR *expr, int mode)
/*
**		Set a value to the environment.
**		(Modes will allow for unicode later.)
**		Returns 0 for success and <0 for errors.
**
***********************************************************************/
{
	return putenv(expr);
}


/***********************************************************************
**
*/	REBCHR *OS_List_Env(void)
/*
***********************************************************************/
{
	extern char **environ;
	int n, len = 0;
	char *str, *cp;

	// compute total size:
	for (n = 0; environ[n]; n++) len += 1 + LEN_STR(environ[n]);

	cp = str = OS_Make(len + 1); // +terminator
	*cp = 0;

	// combine all strings into one:
	for (n = 0; environ[n]; n++) {
		len = LEN_STR(environ[n]);
		strcat(cp, environ[n]);
		cp += len;
		*cp++ = 0;
		*cp = 0;
	}

	return str; // caller will free it
}


/***********************************************************************
**
*/	void OS_Get_Time(REBOL_DAT *dat)
/*
**		Get the current system date and time.
**
***********************************************************************/
{
	struct timeval tv;
	time_t stime;

	gettimeofday(&tv, 0); // (tz field obsolete)
	stime = tv.tv_sec;
	Convert_Date(&stime, dat, -1);
	dat->nano  = tv.tv_usec * 1000;
}


/***********************************************************************
**
*/	i64 OS_Delta_Time(i64 base, int opts)
/*
**		Return time difference in microseconds.
**
**		Base = 0 returns a base time to use for delta.
**		This is used for WAIT and polling devices.
**
**		NOTE: This needs to be precise, but many OSes do not
**		provide a precise time sampling method. So, if the target
**		posix OS does, add the ifdef code in here.
**
***********************************************************************/
{
	struct timeval tv;
	i64 time;

	gettimeofday(&tv,0);

	time = ((i64)tv.tv_sec * 1000000) + tv.tv_usec;

	if (base == 0) return time;

	return time - base;
}


/***********************************************************************
**
*/	REBCHR *OS_To_REBOL_Path(REBCHR *path, int *len)
/*
**		Convert local filename to a REBOL filename.
**		Length of result returned in len arg.
**		The result is temporary. Copy and free it.
**
**		REBDIFF: No longer appends current dir to volume when no
**		root slash is provided (that odd MSDOS c:file case).
**
***********************************************************************/
{
	REBCHR *p;
	int length;

	if (len) length = *len;
	else length = LEN_STR(path);
	p = MAKE_STR(length + 3); // extra room to allow for '/' at end
	COPY_BYTES(p, path, length);
	p[length] = 0;
	if (len) *len = length;
	return p;
}


/***********************************************************************
**
*/	REBCHR *OS_To_Local_Path(REBCHR *path, int *len)
/*
**		Convert REBOL filename to a local filename.
**		Length of result returned in len arg.
**		The result is temporary. Copy and free it.
**
***********************************************************************/
{
	return OS_To_REBOL_Path(path, len); // very posix friendly
}


/***********************************************************************
**
*/	int OS_Get_Current_Dir(REBCHR **path)
/*
**		Return the current directory path as a string.
**		The result should be freed after copy/conversion.
**
***********************************************************************/
{
	*path = MAKE_STR(PATH_MAX);
	if (!getcwd(*path, PATH_MAX-1)) *path[0] = 0;
	return LEN_STR(*path); // Be sure to call free() after usage
}


/***********************************************************************
**
*/	BOOL OS_Set_Current_Dir(REBCHR *path)
/*
**		Set the current directory to local path. Return FALSE
**		on failure.
**
***********************************************************************/
{
	return chdir(path) == 0;
}


/***********************************************************************
**
*/	void OS_File_Time(REBREQ *file, REBOL_DAT *dat)
/*
**		Convert file.time to REBOL date/time format.
**		Time zone is UTC.
**
***********************************************************************/
{
	Convert_Date((time_t *)&(file->file.time.l), dat, 0);
}


/***********************************************************************
**
*/	void *OS_Open_Library(REBCHR *path, REBCNT *error)
/*
**		Load a DLL library and return the handle to it.
**		If zero is returned, error indicates the reason.
**
***********************************************************************/
{
	void *dll = dlopen(path, RTLD_LAZY/*|RTLD_GLOBAL*/);
	*error = 0; // dlerror() returns a char* error message, so there's
				// no immediate way to return an "error code" in *error

	return dll;
}


/***********************************************************************
**
*/	void OS_Close_Library(void *dll)
/*
**		Free a DLL library opened earlier.
**
***********************************************************************/
{
	dlclose(dll);
}


/***********************************************************************
**
*/	void *OS_Find_Function(void *dll, char *funcname)
/*
**		Get a DLL function address from its string name.
**
***********************************************************************/
{
	void *fp = dlsym(dll, funcname);

	return fp;
}


/***********************************************************************
**
*/	REBINT OS_Create_Thread(CFUNC init, void *arg, REBCNT stack_size)
/*
**		Creates a new thread for a REBOL task datatype.
**
**	NOTE:
**		For this to work, the multithreaded library option is
**		needed in the C/C++ code generation settings.
**
**		The Task_Ready stops return until the new task has been
**		initialized (to avoid unknown new thread state).
**
***********************************************************************/
{
	REBINT thread;
/*
	Task_Ready = CreateEvent(NULL, TRUE, FALSE, "REBOL_Task_Launch");
	if (!Task_Ready) return -1;

	thread = _beginthread(init, stack_size, arg);

	if (thread) WaitForSingleObject(Task_Ready, 2000);
	CloseHandle(Task_Ready);
*/
	return 1;
}


/***********************************************************************
**
*/	void OS_Delete_Thread(void)
/*
**		Can be called by a REBOL task to terminate its thread.
**
***********************************************************************/
{
	//_endthread();
}


/***********************************************************************
**
*/	void OS_Task_Ready(REBINT tid)
/*
**		Used for new task startup to resume the thread that
**		launched the new task.
**
***********************************************************************/
{
	//SetEvent(Task_Ready);
}


/***********************************************************************
**
*/	int OS_Create_Process(REBCHR *call, int reserved)
/*
**		Return zero on error.
**
***********************************************************************/
{
	system(call);
	return TRUE;
}

static int Try_Browser(char *browser, REBCHR *url)
{
	REBCHR *cmd = MAKE_STR(LEN_STR(browser) + LEN_STR(url) + 10);
	int result;

	// A temporary solution -- for some versions...
	strcpy(cmd, browser);
	strcat(cmd, " \"");
	strcat(cmd, url);
	strcat(cmd, "\"");
	result = (system(cmd) == 0);
	// printf("result: %d\n", result);
	free(cmd);
	return result;
}

/***********************************************************************
**
*/	int OS_Browse(REBCHR *url, int reserved)
/*
***********************************************************************/
{
	if (Try_Browser("xdg-open", url) || Try_Browser("x-www-browser", url))
		return TRUE;
	return FALSE;
}


/***********************************************************************
**
*/	BOOL OS_Request_File(REBRFR *fr)
/*
***********************************************************************/
{
	return FALSE;
}



#ifdef FROM_R2

Unstuff_Date( time_t *tim, REBVAL *val )
{
    struct	tm	tm;
    REBINT	tz_minutes;
	time_t t=time(0);
	REBINT secs;

	tm = *localtime(&t);
	tz_minutes=Get_Timezone(&tm);
	
	tm.tm_mday=VAL_DATE_DAY(val);
	tm.tm_mon=VAL_DATE_MONTH(val)-1;
	tm.tm_year=VAL_DATE_YEAR(val)-1900;
	if(VAL_TIME_SECS(val)==NO_TIME)
		secs=0;
	else
		secs=VAL_TIME_SECS(val)-60*(30*VAL_DATE_TIMEZONE(val)-tz_minutes);
	tm.tm_hour=secs/3600;
	tm.tm_min=(secs/60)%60;
	tm.tm_sec=secs%60;
	*tim=mktime(&tm);
}

#endif

/***********************************************************************
**
*/	REBSER *OS_GOB_To_Image(REBGOB *gob)
/*
**		Render a GOB into an image. Returns an image or zero if
**		it cannot be done.
**
***********************************************************************/
{
	return 0;
}
