#include<stdio.h>
#include<string.h>
int main(){
	int t,j,i,k,temp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
     long n,count;
	  scanf("%ld",&n);
	  char a[n];
	  scanf("%s",a);
	 char b[n];
	 scanf("%s",b);
	  
	  
      
      for(j=0;j<n;j++){
		 for(k=0;k<n;k++)
		 {
            if(a[j]==b[k])
			{
               temp=a[j];
			   a[j]=a[k];
			   a[k]=temp;
			}
		 }
	  }
	   for(j=0;j<n-1;j++){
		if(a[j]=='?'){
		  for(k=j;k<n;k++)
		  {
            if(b[j]==a[k] && a[k]!=b[k])
			{
               temp=a[j];
			   a[j]=a[k];
			   a[k]=temp;
			}
		  }
		 }
	  }
	  for(j=0;j<n;j++)
	  {
         if(a[j]=='?')
		 {
			a[j]=b[j];
		 }
		 }
	  count=0;
	  for(j=0;j<n;j++)
	  {
		if(b[j]==a[j]){
	       count++;
		}
	  }
	  if(count==n)
	  {
        printf("Yes\n");
	  }
	  else
	  {
		printf("No\n");
	  }
	}     
}