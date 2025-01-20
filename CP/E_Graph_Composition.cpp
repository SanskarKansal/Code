#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        set<pair<int,int>>f;
        set<pair<int,int>>g;
        for(int i=0;i<a;i++){
            int c;
            int d;
            cin>>c;
            cin>>d;
            if(c>d){
                swap(c,d);
            }
            f.insert({c,d});
        }
        for(int i=0;i<b;i++){
            int c;
            int d;
            cin>>c;
            cin>>d;
            if(c>d){
                swap(c,d);
            }
            g.insert({c,d});
        }
        int count = 0;
        for(auto &p : f){
            if(g.find(p) == g.end()){
                count++;
            }
        }
        for(auto &p : g){
            if(f.find(p) == f.end()){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
