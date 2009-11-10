/*********************************************************************
 *
 * Copyright (c) 2004-2009 INFN-CNAF on behalf of the EU DataGrid
 * and EGEE I, II and III
 * For license conditions see LICENSE file or
 * http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * Parts of this code may be based upon or even include verbatim pieces,
 * originally written by other people, in which case the original header
 * follows.
 *
 *********************************************************************/
/*
 * Copyright (c) Members of the EGEE Collaboration. 2004.
 * See http://eu-egee.org/partners/ for details on the copyright holders.
 * For license conditions see the license file or http://eu-egee.org/license.html
 */

package org.glite.voms.ac;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

import javax.security.auth.x500.X500Principal;

import org.bouncycastle.asn1.DEREncodableVector;
import org.bouncycastle.asn1.DEROutputStream;
import org.bouncycastle.asn1.DERSequence;
import org.bouncycastle.asn1.x509.GeneralName;
import org.bouncycastle.asn1.x509.GeneralNames;
import org.bouncycastle.jce.X509Principal;


/**
 * @author mulmo
 *
 * To change the template for this generated type comment go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
public class Util {
    public static GeneralNames generalNameToGeneralNames(GeneralName name) {
        DEREncodableVector v = new DEREncodableVector();
        v.add(name);

        return GeneralNames.getInstance(new DERSequence(v));
    }

    public static GeneralName x500nameToGeneralName(byte[] encodedName) {
        try {
            return new GeneralName(new X509Principal(encodedName));
        } catch (IOException e) {
            throw new IllegalArgumentException("invalid X500 name encoding");
        }
    }

    public static GeneralNames x500nameToGeneralNames(X500Principal name) {
        return generalNameToGeneralNames(x500nameToGeneralName(name.getEncoded()));
    }

    public static X500Principal generalNameToX500Name(GeneralName name) {
        int tag = -1;

        if ((name == null) || ((tag = name.getTagNo()) != 4)) {
            throw new IllegalArgumentException("GeneralName is not a DirectoryName (tag=" + tag + ")");
        }

        try {
            ByteArrayOutputStream b = new ByteArrayOutputStream();
            new DEROutputStream(b).writeObject(name.getName());

            return new X500Principal(b.toByteArray());
        } catch (IOException i) {
            throw new IllegalArgumentException("Bad DN encoding of Attribute Certificate issuer");
        }
    }
    public static X509Principal generalNameToX509Name(GeneralName name) {
        int tag = -1;

        if ((name == null) || ((tag = name.getTagNo()) != 4)) {
            throw new IllegalArgumentException("GeneralName is not a DirectoryName (tag=" + tag + ")");
        }

        try {
            ByteArrayOutputStream b = new ByteArrayOutputStream();
            new DEROutputStream(b).writeObject(name.getName());

            return new X509Principal(b.toByteArray());
        } catch (IOException i) {
            throw new IllegalArgumentException("Bad DN encoding of Attribute Certificate issuer");
        }
    }

}
