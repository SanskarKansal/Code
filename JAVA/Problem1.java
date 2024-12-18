public class Problem1 {
    public static void main(String[] args) {
        Mobile obj1= new Mobile();
        obj1.price=100;
        obj1.brand="samsung";
        Mobile obj2=new Mobile();
        obj2.price=200;
        obj2.brand="oppo";
        obj1.show();
        obj2.show(); 
        int finalprice=obj1.price+obj2.price;
        System.out.println("total price is : "+ finalprice); 
    }
}

class Mobile{
    String brand;
    int price;
    void show(){
        System.out.println("price of "+ brand + " is "+price);
    }
}