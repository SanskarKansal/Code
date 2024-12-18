import java.util.*;
public class Binarysearch {
    static int search(int arr[],int target){
        int start=0;
        int end= arr.length-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                end =mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
     public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter target: ");
        int target= sc.nextInt();
        System.out.print("Enter Size of array: ");
        int size= sc.nextInt();
        int arr[]= new int[size];
        System.out.println("Enter the Inputs: ");
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
        }
        sc.close();
        int ans=search(arr,target)+1;
        if(ans==0){
            System.err.println("element not found");
        }
        else{
            System.err.println("Position is:  "+ans);
        }
    }
}
