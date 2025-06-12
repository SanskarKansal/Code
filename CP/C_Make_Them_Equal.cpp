#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]!=c){
                count++;
                break;
            }
        }
        if(!count){
            cout<<0<<endl;
        }
        else{
            int val=-1;
            for(int i=2;i<=n;i++){
                bool check=true;
                for(int j=i;j<=n;j+=i){
                    if(s[j-1]!=c){
                        check=false;
                        break;
                    }
                }
                if(check){
                    val=i;
                    break;
                }
            }
            if(val==-1){
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
            else{
                cout<<1<<endl;
                cout<<val<<endl;
            }
    
    }
    return 0;
}
