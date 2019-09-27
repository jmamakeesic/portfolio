package store;

import java.io.Serializable;
import static java.lang.Float.parseFloat;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;

@ManagedBean(name="storeBean")
@SessionScoped
public class StoreBean implements Serializable {
  
  DecimalFormat df = new DecimalFormat("0.00");
  private final Component Cpu,Ram,Gpu,Sto,Dis,Os;
  private final Component[] build;
  private static Component[] cart;
  private int cpu=1,ram=3,gpu=1,sto=2,dis=2,os=1; // default configuration
  private int province=1; // default tax rate (BC)
  private final float SHIPPING = 20; // flat shipping rate of $20
  private int reviewType=0,reviewModel=0; // for reviews
  
  public StoreBean() {  
    Cpu = new Component(0);
    Ram = new Component(1);
    Gpu = new Component(2);
    Sto = new Component(3);
    Dis = new Component(4);
    Os  = new Component(5);
    build = new Component[] {Cpu,Ram,Gpu,Sto,Dis,Os};
    cart=null;
  }

  public void setCpu(int x) {cpu = x; build();}
  public void setRam(int x) {ram = x; build();}
  public void setGpu(int x) {gpu = x; build();}
  public void setSto(int x) {sto = x; build();}
  public void setDis(int x) {dis = x; build();}
  public void setOs (int x) { os = x; build();}
  public int getCpu() {return cpu;}
  public int getRam() {return ram;}
  public int getGpu() {return gpu;}
  public int getSto() {return sto;}
  public int getDis() {return dis;}
  public int getOs () {return os ;}
  public void setReviewType (int x) {reviewType  = x;}
  public void setReviewModel(int x) {reviewModel = x;}
  public int getReviewType () {return reviewType ;}
  public int getReviewModel() {return reviewModel;}
  public String getComponent(){
    Component c = new Component(reviewType); 
    c.setSelection(reviewModel); 
    return c.getModel()+" ("+c.getInfo()+")";
  }
  public List<String> getReviews(){
    Component c = new Component(reviewType);
    ArrayList<String> reviews = new ArrayList<>();
    c.setSelection(reviewModel);
    for(String r:c.getReviews())
      reviews.add(r);
    return reviews;
  }
  public void addReview(String r){} // Not yet implemented
  public void loadPreset(int c,int r,int g,int s,int d,int o){
    cpu = c;
    ram = r;
    gpu = g;
    sto = s;
    dis = d;
    os  = o;
    build();
  }
  public Component[] build(){
    build[0].setSelection(cpu);
    build[1].setSelection(ram);
    build[2].setSelection(gpu);
    build[3].setSelection(sto);
    build[4].setSelection(dis);
    build[5].setSelection(os );
    return build;
  }
  // sum component prices, rounded to 2 decimals
  public String getSubtotal(){
    return df.format(parseFloat(Cpu.getPrice())+
                     parseFloat(Ram.getPrice())+
                     parseFloat(Gpu.getPrice())+
                     parseFloat(Sto.getPrice())+
                     parseFloat(Dis.getPrice())+
                     parseFloat(Os .getPrice()));
  }
  public void setProvince(int p) {province = p;}
  public int  getProvince() {return province;}
  // return tax amount by province
  public String getTax(){
    final int AB=0,BC=1,MB=2,NB=3,NL=4,NS=5,ON=6,PE=7,QU=8,SK=9;
    switch(province){
      case AB: return df.format(0.05f * parseFloat(getSubtotal()));
      case BC: return df.format(0.12f * parseFloat(getSubtotal()));
      case MB: return df.format(0.13f * parseFloat(getSubtotal()));
      case NB: return df.format(0.15f * parseFloat(getSubtotal()));
      case NL: return df.format(0.15f * parseFloat(getSubtotal()));
      case NS: return df.format(0.15f * parseFloat(getSubtotal()));
      case ON: return df.format(0.13f * parseFloat(getSubtotal()));
      case PE: return df.format(0.15f * parseFloat(getSubtotal()));
      case QU: return df.format(0.15f * parseFloat(getSubtotal()));
      case SK: return df.format(0.11f * parseFloat(getSubtotal()));
      default: return "";
    }
  }
  // return total purchase cost
  public float getShipping() {return SHIPPING;}
  public String getTotal(){
    return df.format(parseFloat(getSubtotal())+
                     parseFloat(getTax())+
                     SHIPPING);
  }
  public void addToCart() {cart=build();}
  public void emptyCart() {cart=null;}
  public Component[] getCart() {return cart;}
  public String getCartLabel(){
    if(cart!=null) return "Update Cart";
    return "Add to Cart";
  }
}

