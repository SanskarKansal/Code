#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> val(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> val[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            sort(val[i].begin(), val[i].end());
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(val[i][j] != val[i][j-1] + n){
                    ans = -1;
                    break;
                }
            }
            if(ans == -1) break; 
        }
        if(ans == -1){
            cout << ans << endl;
        } else {
            priority_queue<pair<int, int>> pq;
            for(int i = 0; i < n; i++){
                pq.push({val[i][0], i+1});
            }
            vector<int> a;
            while(!pq.empty()){
                a.push_back(pq.top().second);
                pq.pop();
            }
            reverse(a.begin(), a.end());
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
