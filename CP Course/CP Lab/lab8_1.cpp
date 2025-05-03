// given an array of n integers whre ai denote the currency of note that the ith person has the possible currency are 5 10 and 20 
// all the n people are standing in a queue waiting to buy an icecream from x which costs rupees 5.
// initially x has an initial balance of 0check if x will be able to provide change for all people who are waiting to buy an icecream.
// for eg if input values are 5,5,5,10 ,20 then output is yes.

#include<bits/stdc++.h>
using namespace std;

bool solve(int n,vector<int>& arr){
    int fnote=0;
    int tnote=0;
    for(int i=0;i<n;i++){
        if(arr[i]==20){
            if(fnote>0 && tnote>0){
                fnote --;
                tnote--;
            }
            else if(fnote>2){
                fnote -=3;
            }
            else{
                return false;
            }
        }
        else if(arr[i]==10){
            if(fnote>0){
                fnote--;
                tnote++;
            }
            else{
                return false;
            }
        }
        else{
            fnote++;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool ans=solve(n,arr);
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}

/*
6
4
5 10 5 20
5
5 5 10 20 10
6
5 5 10 20 5 10
4
10 5 5 5
4
20 5 10 5
4
5 5 5 5
#yes
#no
#yes
#no
#no
#yes
*/
