#include <iostream>
#include <string>
using namespace std;

int main() {
    long long a;
    cout<<"Enter the page Number : ";
    cin>>a;
    if(a==1) {
        cout<<0;
        return 0;
    }
    int ans;
    int count=0;
    bool flag;
    for(int i=2;count<a-1;i++) {
        int x=i;
        flag = true;
        while(x>0 && flag==true) {
            int lastdigit = x%10;
            x = x/10;
            if(lastdigit%2!=0) {
                flag =false;
            }
        }
        if(flag==false) continue;
         ans=i;
         count++;
    }
    cout<<ans<<endl;
    return 0;
}