#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int len = 0;
                while(i + len < n && j + len < m && a[i + len] == b[j + len]){
                    len++;
                }
                maxlen = max(maxlen, len);
            }
        }
        int ans = (n - maxlen) + (m - maxlen);
        cout << ans << endl;
    }
}
