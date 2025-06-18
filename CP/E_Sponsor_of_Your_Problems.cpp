#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        string a = to_string(l), b = to_string(r);
        int ans = 0;
        int i=0;
        while(i<a.size()) {
            if (a[i] == b[i]){
                ans+=2;
                i++;
            }
            else{
                break;
            }
        }
        while(i<a.size()) {
            int val;
            if(b[i]=='0'){
                val='9'-b[i]+1;
            }
            else{
                val=b[i]-a[i];
            }
            if (val==1){
                ans++;
                i++;
            }
            else{
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
