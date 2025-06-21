#include<bits/stdc++.h>
using namespace std;

int xorUpto(int x){
    if(x % 4 == 0){
        return x;
    }
    if(x % 4 == 1){
        return 1;
        }
    if(x % 4 == 2){
        return x+1;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int x = xorUpto(a - 1);
        if(x == b){
            cout << a << endl;
        }
        else if((x ^ b) == a){
            cout << a + 2 << endl;
        }
        else {
            cout << a + 1 << endl;
        }
    }
}
