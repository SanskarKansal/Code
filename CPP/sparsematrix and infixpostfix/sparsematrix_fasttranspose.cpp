#include <stdio.h>
typedef struct {
        int row;
        int col;
        int value;
    } term;
    void transpose (term a[],term b[])
    {
        int n= b[0].value=a[0].value;
        int c= b[0].row = a[0].col;
        int r= b[0].col=a[0].row;
        int rowTerm[c] , startpos[c];
        startpos[0]=1;
        for(int i=0;i<c;i++)
        {
            rowTerm[i]=0;
        }
        for(int i=1;i<=n;i++)
        rowTerm[a[i].col]++;

        for(int i=1;i<c;i++)
        {
            startpos[i]=startpos[i-1]+rowTerm[i-1];
        }
        for(int i=1;i<=n;i++)
        {
           int j=startpos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value= a[i].value;
        }
        }
    
        int main()
        {
            int r,c,v;
    printf("Enter the no. of row,columns and values recpectively ");
    scanf("%d%d%d",&r,&c,&v);
    term a[v+1];
    term b[v+1];
    a[0].row=r;
    a[0].col=c;
    a[0].value=v;
    for (int i=1;i<=v;i++)
    {
       
         printf("Enter the value of row , column and value");
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    transpose(a,b);
    for(int i=1;i<=v;i++)
    {
        printf("%d %d %d \n",b[i].row,b[i].col,b[i].value);
    }
        }