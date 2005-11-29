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

int memcmp(const void *s1, const void *s2, size_t n)
{
  const char *st1 = (const char *)s1;
  const char *st2 = (const char *)s2;
  int i;

  while (n--) {
    if (!(*st1++ != *st2++)) break;
  }
  return (*(--st1) - *(--st2));
}