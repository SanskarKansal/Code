#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>a(5,0);
        cin>>a[0]>>a[1]>>a[3]>>a[4];
        int count=0;
        int ans=0;
        a[2]=a[1]+a[0];
        count++;
        if(a[1]+a[2]==a[3]){
            count++;
            
        }
        if(a[2]+a[3]==a[4]){
                count++;
            }
        ans=count;
        count=0;
        a[2]=a[3]-a[1];
        if(a[2]+a[1]==a[3]){
            count++;
            
        }
        if(a[2]+a[3]==a[4]){
                count++;
            }
        ans=max(ans,count);
        cout<<ans<<endl;
    }
}