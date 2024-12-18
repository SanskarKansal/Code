#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number " << endl;
    cin >> n ;
    int digit=0;
    int bit=0;
    int count=0;
    int flag=0;
    while(n!=0)
    {
        digit=n%2;
        bit=bit*10+digit;
        n=n>>1;
        if(bit==0)
        {
            count++;
        }
        flag++;
    }
    int ans=bit*pow(10,count);
    cout << ans ;
    int neg=~n;
    int i=0;
    int a=0;
    cout << neg;
    // creating a mask number to take and with neg
    while(i<flag)
    {
        a=a*10+1;
        i++;
    }
    int digit1;
    int digit2;
    while(1)
    {
        digit1=a%10;
        digit2=neg%10;
    }


}