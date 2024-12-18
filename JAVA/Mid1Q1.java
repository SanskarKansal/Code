import java.util.Scanner;
class bubble{
    void bubblesort(int n,int[] arr){
        for(int i=0;i<n;i++){
            boolean a=true;
            for(int j=i;j<n;j++){
                if(arr[i]>arr[j]){
                    int b=arr[i];
                    arr[i]=arr[j];
                    arr[j]=b;
                }
            }
            if(a){
                break;
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
public class Mid1Q1 {
    public static void main(String[] args) {
        int n;
        Scanner sc =new Scanner(System.in);
        System.out.print("enter size Of array: ");
        n=sc.nextInt();
        int[] arr=new int[n];
        System.out.print("enter inputs: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        bubble obj=new bubble();
        obj.bubblesort( n,arr);
    }
}
