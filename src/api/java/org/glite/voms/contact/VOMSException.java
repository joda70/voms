/*********************************************************************
 *
 * Authors: 
 *      Andrea Ceccanti - andrea.ceccanti@cnaf.infn.it 
 *          
 * Copyright (c) 2006-2009 INFN-CNAF on behalf of the EGEE I, II and III
 * For license conditions see LICENSE file or
 * http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * Parts of this code may be based upon or even include verbatim pieces,
 * originally written by other people, in which case the original header
 * follows.
 *
 *********************************************************************/
package org.glite.voms.contact;

/**
 * 
 * @author Andrea Ceccanti
 *
 */
public class VOMSException extends RuntimeException {

    /**
     * 
     */
    private static final long serialVersionUID = 1L;

    public VOMSException( String message ) {

        super( message );
    }

    public VOMSException( String message, Throwable t ) {

        super( message, t );
    }

    public VOMSException( Throwable t ) {

        super( t.getMessage(), t );
    }

}
