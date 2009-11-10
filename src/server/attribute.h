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

#ifndef VOMS_ATTRIBUTE_H
#define VOMS_ATTRIBUTE_H

#include <string>
#include "dbwrap.h"

bool operator==(const gattrib& lhs,
                const gattrib& rhs);

bool operator<(const gattrib& lhs,
               const gattrib& rhs);

#endif /* __ATTRIBUTE_H */
