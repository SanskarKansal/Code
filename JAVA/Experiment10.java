class exception extends Exception{
    String s;
    exception(String s){
        // super(s);
        this.s=s;
    }
    String display(){
        return s;
    }
}
public class Experiment10 {
    public static void main(String[] args) {
        try {
            // exception obj1 =new exception("string is used");
            // System.out.println(obj1.display());
            throw new exception("string is used");
        }
        catch (exception e) {
            System.out.println(e.getMessage());
        }
        finally{
            System.out.println("finally code is executed");
        }
    }
}