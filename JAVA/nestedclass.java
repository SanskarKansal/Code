public class nestedclass{
    class inner{
        private int num=5;
        void display(){
            System.out.println(num);
        }
       
    }
    void innerclass(){
        inner obj2=new inner();
        obj2.display();
        System.out.println("inner variable : "+obj2.num);
    }
    public static void main(String[] args) {
       nestedclass obj =new nestedclass();
       obj.innerclass();
       nestedclass.inner obj3=obj.new  inner();
    }
}