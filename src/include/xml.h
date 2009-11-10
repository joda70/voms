/*********************************************************************
 *
 * Authors: Vincenzo Ciaschini - Vincenzo.Ciaschini@cnaf.infn.it 
 *
 * Copyright (c) 2002-2009 INFN-CNAF on behalf of the EU DataGrid
 * and EGEE I, II and III
 * For license conditions see LICENSE file or
 * http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * Parts of this code may be based upon or even include verbatim pieces,
 * originally written by other people, in which case the original header
 * follows.
 *
 *********************************************************************/
#ifndef VOMS_XML_H
#define VOMS_XML_H
#include "errortype.h"

struct req {
  char *order;
  char **command;
  int  n;
  char *targets;
  char *value;
  int   error;
  int   lifetime;
  int   depth;
  int   base64;
  int   version;
};

struct ans {
  char *data;
  int   datalen;
  char *ac;
  int   aclen;
  struct error **list;

  struct error  *err;
  char *value;
  int error;
  int depth;
  int version;
};

char *XMLEncodeReq(const char *, const char *, const char *, int);
char *XMLEncodeAns(struct error **, const char *, int, const char *, int, int);
int XMLDecodeReq(const char *, struct req *);
int XMLDecodeAns(const char *, struct ans *);
#endif
