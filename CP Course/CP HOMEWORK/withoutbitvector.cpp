#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    int c = n, c0 = 0, c1 = 0;
    while(((c & 1) == 0) && (c != 0)){
        c0++;
        c >>= 1;
    }
    while((c & 1) == 1){
        c1++;
        c >>= 1;
    }
    if(c0 + c1 == 31 || c0 + c1 == 0) return -1;
    int p = c0 + c1;
    n |= (1 << p);
    n &= ~((1 << p) - 1);
    n |= (1 << (c1 - 1)) - 1;
    return n;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}

/*
8
1
2
3
7
15
78
127
13948
#
2
4
5
11
23
83
191
13967

*/