#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        // Code for each test case
        long long n;
        cin >>n;
        long long odd = 0, even = 0;
        map<long long, int> mp;
        mp[0] = 1;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool found = false;
        for (long long i=0;i<n;i++) {
            long long x;
            x=a[i];
            if(i%2){
                even+=x;
            }
            else{
                odd+=x;
            }
            long long diff = odd - even;
            if (mp.count(diff)){
                found=true;
            }
            if(found){
                break;
            }
            mp[diff] = 1;
        }
        if(found){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}