/*********************************************************************
 *
 * Authors: Vincenzo Ciaschini - Vincenzo.Ciaschini@cnaf.infn.it 
 *
 * Copyright (c) 2002, 2003 INFN-CNAF on behalf of the EU DataGrid.
 * For license conditions see LICENSE file or
 * http://www.edg.org/license.html
 *
 * Parts of this code may be based upon or even include verbatim pieces,
 * originally written by other people, in which case the original header
 * follows.
 *
 *********************************************************************/
#ifndef VOMS_LOG_H
#define VOMS_LOG_H

typedef enum { T_PRE = 0x00, T_STARTUP = 0x01, T_REQUEST = 0x02, T_RESULT = 0x04 } logtypes;
typedef enum { LEV_ERROR = 0, LEV_WARN, LEV_INFO, LEV_DEBUG, LEV_NONE} loglevels;

#include "config.h"

#include <stdio.h>

extern void       *LogInit();
extern int         LogRemStreamer(void *, void *);
extern void       *LogAddStreamer(void *, void *, void *, const char *, int, int, 
                                  int (*)(void *, loglevels), 
                                  int (*)(void *, int, int, const char *), 
                                  void (*)(void *), int);
extern void        LogDestroy(void *);
extern loglevels   LogLevel(void *, loglevels);
extern logtypes    LogType(void *, int);
extern const char *LogDateFormat(void *, const char *);
extern const char *LogService(void *, const char *);
extern const char *LogFormat(void *, const char *);
extern int         LogMessage(void *, loglevels, logtypes, const char *, const char *, int, const char *);
extern int         LogMessageF(const char *, int, const char *, void *, loglevels, logtypes, const char *, ...);
extern int         LogBuffer(FILE *, void *, loglevels, logtypes, const char *);
extern logtypes    SetCurLogType(void *, logtypes);

#define LOG(h, lev, type, str) \
LogMessage((h), (lev), (type), (str), FUNC_NAME, __LINE__, __FILE__)

#define LOGM LogMessageF 

#define VARP FUNC_NAME, __LINE__, __FILE__

#endif /* H_LOG_H */