#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        vector<int> visit(n+1);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i+1;
            visit[i+1] = a[i].first;
        }
        sort(a.rbegin(), a.rend());
        vector<int> pos(n+1,0);
        int x = 1;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){ 
                pos[a[i].second] = x;
            }
            else{ 
                pos[a[i].second] = -x;
                x++;
            }
        }
        long long total = 0;
        for(int i = 1; i <= n; i++){
            total += 2LL * abs(pos[i]) * visit[i];
        }
        cout << total << "\n";
        cout << 0 << " ";
        for(int i = 1; i <= n; i++){ 
            cout << pos[i] << " ";
        }
        cout << "\n";
    }
}
