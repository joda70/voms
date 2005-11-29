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
#include "config.h"

#include <string.h>
#include <stdlib.h>

char *strndup(const char *s, size_t n)
{
  int l;
  char *r;

  if (!s)
    return NULL;

  if (r=(char *)malloc(n+1)) {
    r[n]='\0';
    memcpy(r,s,n);
  }
  return r;
}