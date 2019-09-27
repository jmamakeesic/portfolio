package cookie;

import java.io.Serializable;
import java.util.TimeZone;
import java.net.InetAddress;
import java.net.UnknownHostException;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;

@ManagedBean(name="cookieBean")
@SessionScoped
public class CookieBean implements Serializable{
    private int visits;
    private final String ip;
    private final String timezone;

    public CookieBean() throws UnknownHostException{
        this.visits = 0;
        this.ip = InetAddress.getLocalHost().getHostAddress()+" ("+
                  InetAddress.getLocalHost().getHostName()+")";
        this.timezone = TimeZone.getDefault().getDisplayName();
    }
    public int getVisits(){
        return visits;
    }
    public void incVisits(){
        visits++;
    }
    public String getIp(){
        return ip;
    }
    public String getTimezone(){
        return timezone;
    }
}
