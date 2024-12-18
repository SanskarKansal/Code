public class Exp10_1 {
    public static void main(String[] args) {
        try {
            throw new Exception("string used");
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        finally{
            System.out.println("finally code is executed");
        }
    }
}
