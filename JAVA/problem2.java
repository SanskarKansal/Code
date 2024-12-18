public class problem2 {
    public static void main(String[] args) {
        String a="name";
        String b="name";
        System.out.println("string 1==string2: "+ check1(a,b));
        System.out.println("string 1!=string2: "+ check2(a,b));
        System.out.println("string 1.equals(string2): "+ check3(a,b));
    }
    static boolean check1(String s1, String s2){
        return s1==s2;
    }
    static boolean check2(String s1, String s2){
        return s1!=s2;
    }
    static boolean check3(String s1, String s2){
        return s1.equals(s2);
    }
}
