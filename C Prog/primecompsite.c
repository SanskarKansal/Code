#include<stdio.h>
int checkprime(int j){
    int rep=0;
    int i;
    for(i=2;i<j/2;i++){
        if(j%i==0){
            rep++;
        }
    }
        if(rep ==0){
            return 1;
        }
        if(rep>0){
            return 0;
        }
}
int checkcomposite(int j){
    int rep=0;
    int i;
    for(i=2;i<j/2;i++){
        if(j%i==0){
            rep++;
        }
    }
        if(rep ==0){
            return 0;
        }
        if(rep>0){
            return 1;
        } 
}
int main(){
    int i,j,m=2,p=2,l,u,c;
    int count =0;
    int n;
    printf("enter the number in the series");
    scanf("%d",&n);
    for(i=0;count<n;i++){
        int prime=0,composite=0;
        for(j=m;prime<=p;j++){
            l=checkprime(j);
            if(l==0){
                j++;
            }
            if(l==1){
                printf(" %d ",j);
                count++;
                prime++;
                j++;
            }
        }
        m=j+1;
        for(j=m;composite<=p;j++){
            u=checkcomposite(j);
            if(u==0){
                j++;
            }
            if(u==1){
                printf(" %d ",j);
                count++;
                composite++;
                j++;
            }
        }
        m=j+1;
        p++;
    }
    return 0;
}