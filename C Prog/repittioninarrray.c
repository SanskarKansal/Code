#include<stdio.h>
int main(){
    int array[8],i,j,m;
    printf("enter number for aaray\n");
    for(i=0;i<=7;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<=7;i++){
        int count=0;
        for(j=i;j<=7;j++){
            int wrong=0;
            if(array[i]==array[j]){
                for(m=0;m<i;m++){
                    if(array[m]==array[i]){
                        wrong++;
                    }
                }
                if(wrong!=0){
            continue;}
               else{ count++;}
            }
        }
        if(count!=0){
        printf("repitiion of %d is %d \n",array[i],count);}
    }
    return 0;
}
