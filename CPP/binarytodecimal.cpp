#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int binary;
    cout << "enter the binary form " << endl;
    cin >> binary ;
    int ans=0,bit=0;
    int i=0;
    while(binary!=0)
    {
        bit=binary%10;
        ans=bit*pow(2,i)+ans;
        i++;
        binary=binary/10;
    }
    cout << ans ;
 }