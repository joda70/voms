import java.util.Collection;
import java.util.Vector;

import org.glite.voms.*;
import org.glite.voms.contact.*;
import org.glite.voms.ac.*;

class contactvoms4 {
    public static void main(String[] args) {
        UserCredentials c = UserCredentials.instance(args[0], args[1]);
        VOMSProxyInit vpi = VOMSProxyInit.instance(c);
        vpi.setProxyType(VOMSProxyBuilder.GT2_PROXY);
        vpi.setProxyOutputFile(args[2]);
        VOMSRequestOptions o = new VOMSRequestOptions();
        o.setVoName("voms1");
        o.addFQAN("all");
        Collection col = new Vector();
        col.add(o);
        vpi.getVomsProxy(col);
    }
}
