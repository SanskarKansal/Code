class Phone {
    String make;
    String model;
    int year;
    public Phone(String make,String model,int year){
        this.make=make;
        this.model=model;
        this.year=year;
    }
    public Phone(){
        this.make="";
        this.model="";
        this.year=0;
    }
    String tostring(){
        String output="This phone has make : " +this.make+ ". It's model : "+this.model+".It's manufacture year : "+this.year;
        return output;
    }
    void getter(){
        System.out.println("The make of this phone: "+ this.make);
        System.out.println("The model of this phone: "+ this.model);
        System.out.println("The manufacture year of this phone: "+ this.year);
    }
    void setter(String make,String model,int year){
        this.make=make;
        this.model=model;
        this.year=year;
    }
    boolean isObsolete(){
        return (2024-this.year>10);
    } 
}
public class Phonecheck{
    public static void main(String[] args) {
        Phone obj1= new Phone();
        obj1.setter("a1","b1",2022);
        obj1.getter();
        String output =obj1.tostring();
        boolean check=obj1.isObsolete();
        System.out.println("discription: "+output);
        System.out.println("Is manufactured 10 year ago : "+check);
    }
}
