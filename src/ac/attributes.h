/*********************************************************************
 *
 * Authors: Vincenzo Ciaschini - Vincenzo.Ciaschini@cnaf.infn.it 
 *          Valerio Venturi    - Valerio.Venturi@cnaf.infn.it
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
#include "config.h"

#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/asn1_mac.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/err.h>
#include <openssl/asn1.h>
#include <openssl/stack.h>
#include <openssl/safestack.h>
#include "newformat.h"
#include "acerrors.h"
#include "acstack.h"

typedef struct ACATTRIBUTE {
  ASN1_OCTET_STRING *name;
  ASN1_OCTET_STRING *qualifier;
  ASN1_OCTET_STRING *value;
} AC_ATTRIBUTE;

typedef struct ACATTHOLDER {
  STACK_OF(GENERAL_NAME) *grantor;
  STACK_OF(AC_ATTRIBUTE) *attributes;
} AC_ATT_HOLDER;

typedef struct ACFULLATTRIBUTES {
  STACK_OF(AC_ATT_HOLDER) *providers;
} AC_FULL_ATTRIBUTES;

DECL_STACK(AC_ATTRIBUTE);
DECL_STACK(AC_ATT_HOLDER);
DECL_STACK(AC_FULL_ATTRIBUTES);

extern int i2d_AC_ATTRIBUTE(AC_ATTRIBUTE *, unsigned char **);
extern int i2d_AC_ATT_HOLDER(AC_ATT_HOLDER *, unsigned char **);
extern int i2d_AC_FULL_ATTRIBUTES(AC_FULL_ATTRIBUTES *, unsigned char **);

extern AC_ATTRIBUTE *d2i_AC_ATTRIBUTE(AC_ATTRIBUTE **, unsigned char **, long);
extern AC_ATT_HOLDER *d2i_AC_ATT_HOLDER(AC_ATT_HOLDER **, unsigned char **, long);
extern AC_FULL_ATTRIBUTES *d2i_AC_FULL_ATTRIBUTES(AC_FULL_ATTRIBUTES **, unsigned char **, long);

extern AC_ATTRIBUTE *AC_ATTRIBUTE_new();
extern AC_ATT_HOLDER *AC_ATT_HOLDER_new();
extern AC_FULL_ATTRIBUTES *AC_FULL_ATTRIBUTES_new();

extern void AC_ATTRIBUTE_free(AC_ATTRIBUTE *);
extern void AC_ATT_HOLDER_free(AC_ATT_HOLDER *);
extern void AC_FULL_ATTRIBUTES_free(AC_FULL_ATTRIBUTES *);
