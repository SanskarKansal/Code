class modifier{
    public int a=1;
    private int b=2;
    int c=3;
    void displaya(){
        System.out.println("value of a Is "+ a);
    }
    void displayb(){
        int d=b;
        System.out.println("value of b Is "+ d);
    }
    void displayc(){
        System.out.println("value of a Is "+ c);
    }
} 
public class MId1Q2 {
    public static void main(String[] args) {
        modifier obj=new modifier();
        System.out.println("public class acessed in other class and value is "+obj.a);
        System.out.println("public can be accessed in different class in same package");
        //System.out.println(obj.b);
        System.out.println("b can only be accesed in same class");
        System.out.println(obj.c);
        System.out.println("c can only be accesed in same package");
    }
}
