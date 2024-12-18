#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int solve (char* S, char k) {
   int l=strlen(S);
   int i,count=0;
   for(i=0;i<l;i++)
   {
    if(S[i]==k)
    {
        count++;
    }
   }
   return count;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        while(getchar()!='\n');
        char* S = (char*)malloc(200000 * sizeof(char));
        fgets(S,200000,stdin);
        char k;  
        scanf("%c",&k);

        int out_ = solve(S, k);
        printf("%d", out_);
        printf("\n");
    }
}