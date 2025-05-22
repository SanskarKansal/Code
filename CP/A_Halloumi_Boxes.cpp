#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k>=2){
            cout<<"YES"<<endl;
        }
        else{
            int val=a[0];
            int i=0;
            for(i=1;i<n;i++){
                if(val>a[i]){
                    break;
                }
                else{
                    val=a[i];
                }
            }
            if(i==n){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}