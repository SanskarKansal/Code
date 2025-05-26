#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        // Code for each test case
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int low=1;
        int high=60;
        long long ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long val=1LL <<mid;
            set<long long>st;
            for(int i=0;i<n;i++){
                st.insert(a[i]%val);
            }
            if(st.size()==2){
                ans=val;
                break;
            }
            else if(st.size()>2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}