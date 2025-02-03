#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int zero=0;
        int one=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(one==0){
                    break;
                }
                one--;
            }
            else{
                if(zero==0){
                    break;
                }
                zero--;
            }
        }
        cout<<one+zero<<endl;
    }
    return 0;
}
