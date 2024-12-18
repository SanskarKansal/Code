public class outerclass {
    private int val=2;
    private void display(){
        System.out.println("In outer class and Value:"+val);
    }
    class inner{
        private int check=1;
        void modify(){
            val+=2;
            System.out.println("In inner class and modified value:"+val);
            display();
        }
    }
    void callinner(){
        inner obj2=new inner();
         obj2.modify();
        System.out.println("inner variable : "+obj2.check);
    }
    public static void main(String[] args) {
        outerclass obj=new outerclass();
        obj.callinner();
        outerclass.inner obj3=obj.new inner();
        obj3.modify();
    }
}