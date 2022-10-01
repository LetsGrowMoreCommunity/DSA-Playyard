package OOPS.Inheritence;

import java.io.*;


class vehicle {
 
int id;
static String type;




  vehicle(int id, String type){

    this.id = id;
    this.type = type;
  }
    
  void fun() {
   
   
    System.out.println("Vehicle is printing");
  }
}

class bike extends vehicle {
  
    String bname;
    String bmodel;
  bike(int id, String bname, String bmodel){
   super(id,type);
    this.id = id;
    this.bname = bname;
    this.bmodel = bmodel;
  }

  void fun() {
 
  
    System.out.println("BIKE FUCTION IS PRINTING");
  }
}
 

class car extends vehicle {
  
   

    String cname;
    String cmodel;

car(int id, String type, String cname, String cmodel) {
        super(id, type);
        this.id = id;
        this.type=type;
    this.cname = cname;
    this.cmodel = cmodel;
    
    }
}
 class main{

public static void main(String args[]) {
 
 
    car c = new car(3,"sedan","Tata","zest");

     System.out.println(c.cmodel+c.cname+c.type+c.id);
    
    
  }
 }


