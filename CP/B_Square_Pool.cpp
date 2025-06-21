#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long s;
        cin>>n>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            int dx,dy;
            long long x,y;
            cin>>dx>>dy>>x>>y;
            long long v = (1LL*dx*x - 1LL*dy*y) % s;
            if(v<0){
                v+=s;
            }
            if(v==0){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
