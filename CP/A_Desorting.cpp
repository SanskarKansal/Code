#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        long long ans=LLONG_MAX;
        long long prev;
        cin>>prev;
        for(int i=1;i<n;i++){
            long long cur;
            cin>>cur;
            ans=min(ans,cur-prev);
            prev=cur;
        }
        if(ans<0){
            ans=0;
        }
        else{
            ans=1+ans/2;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}