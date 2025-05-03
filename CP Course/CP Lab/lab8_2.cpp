

#include<bits/stdc++.h>
using namespace std;

void assign(int n,vector<bool>& bits){
    for(int i=0;i<32;i++){
        int val=n&(int(pow(2,31-i)));
        if(val){
            bits[i]=true;
        }
    }
}

int solve(int n){
    vector<bool>bits(32,false);
    assign(n,bits);
    int i=31;
    for(i=31;i>0;i--){
        if(bits[i] && !bits[i-1]){
            swap(bits[i],bits[i-1]);
            break;
        }
    }
    i++;
    int j=31;
    while(i<j){
        while(j>=0 && bits[j]){
            j--;
        }
        if(i>=j){
            break;
        }
        if(bits[i]==1){
            swap(bits[i],bits[j]);
            i++;
            j--;
        }
        else{
            break;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++){
        bool val=bits[i];
        if(val){
            ans+=int(pow(2,31-i));
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=solve(n);
        cout<<ans<<endl;
    }
}

/*
6
1
2
3
5
6
12

#
2
4
5
17
83
191

*/