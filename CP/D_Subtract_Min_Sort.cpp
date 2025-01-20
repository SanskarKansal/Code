#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int>val(n);
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        for(int i=1;i<n;i++){
            if(val[i]<val[i-1]){
                ans=-1;
                break;
            }
            else{
                val[i]-=val[i-1];
            }
        }
        if(ans==-1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
