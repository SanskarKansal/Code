public class problem3 {
    public static void main(String[] args) {
        Dog obj1=new Dog();
        obj1.name="spot";
        obj1.says="Ruff!";
        obj1.show();
        Dog obj2=new Dog();
        obj2.name="scruffy";
        obj2.says="Wurf";
        obj2.show();
        Dog obj3=obj1;
        System.out.println("dog1.name==dog3.name: "+ check1(obj1.name,obj3.name));
        System.out.println("dog1.says==dog3.says: "+ check1(obj1.says,obj3.says));
        System.out.println("dog1.name.equals(dog3.name): "+ check2(obj1.name,obj1.name));
        System.out.println("dog1.says.equals(dog3.says): "+check2(obj1.says,obj3.says));
    }
    static boolean check1(String s1,String s2){
        return s1==s2;
    }
    static boolean check2(String s1,String s2){
        return s1.equals(s2);
    }
}

class Dog{
    String name;
    String says;
    void show(){
        System.out.println("The Dog: "+name+" says: "+says);
    }
}