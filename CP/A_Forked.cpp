#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<pair<int,int>> getMoves(int x,int y,int a,int b){
    vector<pair<int,int>> moves;
    int dx[] = {a, a, -a, -a, b, b, -b, -b};
    int dy[] = {b, -b, b, -b, a, -a, a, -a};
    for(int i=0;i<8;i++){
        moves.push_back({x + dx[i], y + dy[i]});
    }
    return moves;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        int kx,ky;
        cin>>kx>>ky;
        int qx,qy;
        cin>>qx>>qy;
        
        set<pair<int,int>> kmoves, qmoves;
        for(auto p : getMoves`(kx, ky, a, b)){
            kmoves.insert(p);
        }
        for(auto p : getMoves(qx, qy, a, b)){
            qmoves.insert(p);
        }
        int common = 0;
        for(auto p : kmoves){
            if(qmoves.count(p)){
                common++;
            }
        }
        cout << common << endl;
    }
    return 0;
}
