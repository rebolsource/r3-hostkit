/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: Event Types
**  Build: A107
**  Date:  9-Sep-2010
**  File:  reb-evtypes.h
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-boot.r)
**
***********************************************************************/


enum event_types {
    EVT_IGNORE,
    EVT_INTERRUPT,
    EVT_DEVICE,
    EVT_CALLBACK,
    EVT_CUSTOM,
    EVT_ERROR,
    EVT_INIT,
    EVT_OPEN,
    EVT_CLOSE,
    EVT_CONNECT,
    EVT_ACCEPT,
    EVT_READ,
    EVT_WRITE,
    EVT_WROTE,
    EVT_LOOKUP,
    EVT_READY,
    EVT_DONE,
    EVT_TIME,
    EVT_SHOW,
    EVT_HIDE,
    EVT_OFFSET,
    EVT_RESIZE,
    EVT_ACTIVE,
    EVT_INACTIVE,
    EVT_MINIMIZE,
    EVT_MAXIMIZE,
    EVT_RESTORE,
    EVT_MOVE,
    EVT_DOWN,
    EVT_UP,
    EVT_ALT_DOWN,
    EVT_ALT_UP,
    EVT_AUX_DOWN,
    EVT_AUX_UP,
    EVT_KEY,
    EVT_KEY_UP,
    EVT_SCROLL_LINE,
    EVT_SCROLL_PAGE,
    EVT_DROP_FILE,
	EVT_MAX
};

enum event_keys {
    EVK_NONE,
    EVK_PAGE_UP,
    EVK_PAGE_DOWN,
    EVK_END,
    EVK_HOME,
    EVK_LEFT,
    EVK_UP,
    EVK_RIGHT,
    EVK_DOWN,
    EVK_INSERT,
    EVK_DELETE,
    EVK_F1,
    EVK_F2,
    EVK_F3,
    EVK_F4,
    EVK_F5,
    EVK_F6,
    EVK_F7,
    EVK_F8,
    EVK_F9,
    EVK_F10,
    EVK_F11,
    EVK_F12,
	EVK_MAX
};

