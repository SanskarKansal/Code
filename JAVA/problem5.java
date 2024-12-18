public class problem5 {
    static String s1="check1";
    static String s2;
    static{
        s2="check2";
        System.out.println("string initialised");
    }
    static void print(){
        System.out.println("string S1: "+s1);
        System.out.println("string S2: "+s2);
    }
    public static void main(String[] args) {
        print();
    }
}