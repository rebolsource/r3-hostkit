# REBOL 3.0 Host Makefile - Build A96

C= gcc
CFLAGS= -c -O1 -DUNICODE -fpack-struct -I src/include/
LIBS= r3lib.lib -L c:/mingw/lib/ -lm -lwsock32 -lcomdlg32
#-lc -lm -lstdc++

S= src
O= obj
I= src/include

# Included from reb-host.h:
INCS = \
	$I/reb-config.h\
	$I/reb-c.h\
	$I/reb-defs.h\
	$I/reb-args.h\
	$I/reb-device.h\
	$I/reb-file.h\
	$I/reb-event.h\
	$I/reb-evtypes.h\
	$I/reb-net.h\
	$I/reb-filereq.h\

OBJS =	\
	$O/host-main.o\
	$O/host-args.o\
	$O/host-device.o\
	$O/host-stdio.o\
	$O/dev-net.o\
	$O/dev-dns.o\
	$O/host-init.o\
	$O/host-lib.o\
	$O/dev-stdio.o\
	$O/dev-event.o\
	$O/dev-file.o\
	$O/dev-clipboard.o\

# Link the files
core:	$(OBJS)
	$C -o core.exe  $(OBJS) $(LIBS)
	strip core.exe

clean:
	del /q obj\*
	make core

# Compile:
$O/host-main.o:     $S/os/host-main.c $(INCS) $I/reb-host.h $I/host-lib.h $I/rebol-lib.h $I/host-init.h
	$C $(CFLAGS) -o $O/host-main.o $S/os/host-main.c

$O/host-args.o:     $S/os/host-args.c $(INCS) $I/reb-config.h $I/reb-c.h $I/reb-args.h
	$C $(CFLAGS) -o $O/host-args.o $S/os/host-args.c

$O/host-device.o:   $S/os/host-device.c $(INCS) $I/reb-host.h $I/host-lib.h $I/rebol-lib.h
	$C $(CFLAGS) -o $O/host-device.o $S/os/host-device.c

$O/host-stdio.o:    $S/os/host-stdio.c $(INCS) $I/reb-host.h $I/host-lib.h
	$C $(CFLAGS) -o $O/host-stdio.o $S/os/host-stdio.c

$O/dev-net.o:       $S/os/dev-net.c $(INCS) $I/reb-host.h $I/host-lib.h $I/sys-net.h
	$C $(CFLAGS) -o $O/dev-net.o $S/os/dev-net.c

$O/dev-dns.o:       $S/os/dev-dns.c $(INCS) $I/reb-host.h $I/host-lib.h $I/sys-net.h
	$C $(CFLAGS) -o $O/dev-dns.o $S/os/dev-dns.c

$O/host-init.o:     $S/os/host-init.c $(INCS) 
	$C $(CFLAGS) -o $O/host-init.o $S/os/host-init.c

$O/host-lib.o:      $S/os/win32/host-lib.c $(INCS) $I/reb-host.h $I/host-lib.h
	$C $(CFLAGS) -o $O/host-lib.o $S/os/win32/host-lib.c

$O/dev-stdio.o:     $S/os/win32/dev-stdio.c $(INCS) $I/reb-host.h $I/host-lib.h
	$C $(CFLAGS) -o $O/dev-stdio.o $S/os/win32/dev-stdio.c

$O/dev-event.o:     $S/os/win32/dev-event.c $(INCS) $I/reb-host.h $I/host-lib.h
	$C $(CFLAGS) -o $O/dev-event.o $S/os/win32/dev-event.c

$O/dev-file.o:      $S/os/win32/dev-file.c $(INCS) $I/reb-host.h $I/host-lib.h
	$C $(CFLAGS) -o $O/dev-file.o $S/os/win32/dev-file.c

$O/dev-clipboard.o: $S/os/win32/dev-clipboard.c $(INCS) $I/reb-host.h $I/host-lib.h $I/sys-net.h
	$C $(CFLAGS) -o $O/dev-clipboard.o $S/os/win32/dev-clipboard.c

