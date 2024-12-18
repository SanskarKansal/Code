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
    while(n!=0)
    {
        digit=n%2;
        bit=bit*10+digit;
        n=n>>1;
        if(bit==0)
        {
            count++;
        }
    }
    int ans=bit*pow(10,count);
    cout << ans ;
}