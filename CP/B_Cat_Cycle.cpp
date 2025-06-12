#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        long long b = ((k - 1) % n + 1);
        if(n % 2 == 0){
            cout << b <<endl;
        }
        else{
            long long shift = (k - 1) / (n / 2);
            b = (b + shift - 1) % n + 1;
            cout << b << endl;;
        }
    }
}
