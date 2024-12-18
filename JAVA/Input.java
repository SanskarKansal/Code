import java.util.*;
public class Input {
    public static void main(String[] args) {
        Scanner obj =new Scanner(System.in);
        System.out.println("Enter input: ");
        String name=obj.nextLine();
        System.out.println("Entered  input: " +name);
        obj.close();
    }
}