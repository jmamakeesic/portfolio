package store;

import java.io.Serializable;
import java.util.LinkedList;

public class Component implements Serializable {
  
  // component attributes
  private final int type;
  private int s;
  private String model,price,info;
  private final String[][][] data={{
    // CPU         PRICE  INFO
    {"i3-8100B"   ,"170", "1.6GHz  4MB 4-core  4-thread"},
    {"i5-8250U"   ,"385", "1.6GHz  6MB 4-core  8-thread"},
    {"i7-8750H"   ,"515", "2.2GHz  9MB 6-core 12-thread"},
    {"i9-8950HK"  ,"760", "2.9GHz 12MB 6-core 12-thread"}},{
    // RAM         PRICE  INFO
    {"1 x 4GB"    ,"25" , "Crucial DDR4 2.4GHz"},
    {"2 x 4GB"    ,"45" , "Crucial DDR4 2.4GHz"},
    {"1 x 8GB"    ,"45" , "Crucial DDR4 2.7GHz"},
    {"2 x 8GB"    ,"80" , "Crucial DDR4 2.7GHz"},
    {"1 x 16GB"   ,"125", "Crucial DDR4 2.4GHz"},
    {"2 x 16GB"   ,"170", "Crucial DDR4 2.7GHz"}},{
    // GPU         PRICE  INFO
    {"UHD 630"    ,"0"  , "Integrated  128-bit"},
    {"MX 150"     ,"100", "GeForce 2GB  64-bit"},
    {"GTX 1050"   ,"145", "GeForce 4GB 128-bit"},
    {"GTX 1080"   ,"650", "GeForce 8GB 256-bit"}},{
    // Storage     PRICE  INFO
    {"500GB HDD"  ,"70" , "Seagate BarraCuda Pro 7200RPM"},
    {"1TB HDD"    ,"100", "Seagate BarraCuda 5400RPM"    },
    {"2TB HDD"    ,"150", "Seagate BarraCuda 5400RPM"    },
    {"500GB SSD"  ,"130", "Samsung 860 EVO"              },
    {"1TB SSD"    ,"220", "Samsung 860 EVO"              },
    {"2TB SSD"    ,"450", "Samsung 860 EVO"              },
    {"4TB SSD"    ,"900", "Samsung 860 EVO"              }},{
    // Display     PRICE  INFO
    {"WXGA Matte" ,"90" , "Resolution: 1280x800" },
    {"WXGA Glossy","90" , "Resolution: 1280x800" },
    {"FHD Matte"  ,"120", "Resolution: 1920x1080"},
    {"FHD Glossy" ,"120", "Resolution: 1920x1080"}},{
    // OS          PRICE  INFO
    {"Linux Mint" ,"0"  , "Latest version of Linux Mint (v19)" },
    {"Win 10 Home","140", "Latest version of Microsoft Windows"},
    {"Win 10 Pro" ,"200", "Latest version of Microsoft Windows"}}
  };
  
  // component reviews
  private final LinkedList<String> 
    cpu0 = new LinkedList<>(),
    cpu1 = new LinkedList<>(),
    cpu2 = new LinkedList<>(),
    cpu3 = new LinkedList<>(),
    ram0 = new LinkedList<>(),
    ram1 = new LinkedList<>(),
    ram2 = new LinkedList<>(),
    ram3 = new LinkedList<>(),
    ram4 = new LinkedList<>(),
    ram5 = new LinkedList<>(),
    gpu0 = new LinkedList<>(),
    gpu1 = new LinkedList<>(),
    gpu2 = new LinkedList<>(),
    gpu3 = new LinkedList<>(),
    sto0 = new LinkedList<>(),
    sto1 = new LinkedList<>(),
    sto2 = new LinkedList<>(),
    sto3 = new LinkedList<>(),
    sto4 = new LinkedList<>(),
    sto5 = new LinkedList<>(),
    sto6 = new LinkedList<>(),
    dis0 = new LinkedList<>(),
    dis1 = new LinkedList<>(),
    dis2 = new LinkedList<>(),
    dis3 = new LinkedList<>(),
    os0  = new LinkedList<>(),
    os1  = new LinkedList<>(),
    os2  = new LinkedList<>();
  private final LinkedList<String>[][] allReviews = new LinkedList[][]{
    {cpu0,cpu1,cpu2,cpu3               },
    {ram0,ram1,ram2,ram3,ram4,ram5     },
    {gpu0,gpu1,gpu2,gpu3               },
    {sto0,sto1,sto2,sto3,sto4,sto5,sto6},
    {dis0,dis1,dis2,dis3               },
    {os0 ,os1 ,os2                     }
  };
  private LinkedList<String> reviews = new LinkedList();
  
  // initialize component type and sample review
  public Component(int t) {
    type = t;
    for(LinkedList<String> c:allReviews[t]) c.add("Nice component!");
  }
  // set component data by selection
  public void setSelection(int s) {
    this.s = s;
    final int MODEL=0,PRICE=1,INFO=2;
    model = data[type][s][MODEL];
    price = data[type][s][PRICE];
    info  = data[type][s][INFO ];
    reviews = allReviews[type][s];
  }
  public String getModel() {return model;}
  public String getPrice() {return price;}
  public String getInfo () {return info ;}
  public LinkedList<String> getReviews() {return reviews;}
}
