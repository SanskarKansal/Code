#include<bits/stdc++.h>
using namespace std;

void solve(int m, vector<int>& a){
    int val=0;
    for(int i=0;i<m+2;i++){
        val^=a[i];
    }
    for(int i=1;i<=m;i++){
        val^=i;
    }
    int pos =val& (-val);
    int x=0;
    int y=0;
    for(int i=0;i<m+2;i++){
        if(a[i] & pos){
            x^=a[i];
        }
        else{
            y^=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        if(i & pos){
            x^=i;
        }
        else{
            y^=i;
        }
    }
    if(x>y){
        swap(x,y);
    }
    cout<<x<<" "<<y<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin>>m;
        vector<int>a(m+2);
        for(int i=0;i<m+2;i++){
            cin>>a[i];
        }
        if(m<2){
            cout<<-1<<endl;
        }
        else{
            solve(m,a);
        }
    }
    return 0;
}

/*
9
2
1 2 1 2
1
1 1 1
5
1 2 3 4 5 1 3
6
1 2 5 3 4 6 1 3
6
1 2 4 3 5 6 2 4
6
1 3 4 2 5 6 3 6
6
1 5 4 2 6 3 1 6
6
1 5 2 3 6 6 4 5
6
1 4 2 5 1 3 6 2
# 1 2
#-1
#1 3
#1 3
#2 4
#3 6
#1 6
#5 6
#1 2
*/