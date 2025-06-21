#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        int a = l1*b1 + l2*b2 + l3*b3;
        int s = sqrt(a);
        if(s*s != a){
            cout<<"NO\n";
            continue;
        }
        bool check = false;
        if(b1==b2 && b2==b3 && b1==s && l1+l2+l3==s){;
            check=true;
        }
        if(l1==l2 && l2==l3 && l1==s && b1+b2+b3==s){
            check=true;
        }
        if(!check){
            if(l1==s){
                int h = s - b1;
                if(h>0 && b2==h && b3==h && l2+l3==s){
                    check=true;
                }
            }
            if(b1==s){
                int w = s - l1;
                if(w>0 && l2==w && l3==w && b2+b3==s){
                    check=true;
                }
            }
        }
        cout<<(check?"YES\n":"NO\n");
    }
    return 0;
}
