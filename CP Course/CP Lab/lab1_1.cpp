#include<iostream>
#include<vector>
using namespace std;

void seive(vector<bool>& prime, int n){
    for(int val=2;val*val<=n;val++){
        if(prime[val]){
            for(int i=val*val;i<=n;i+=val){
                prime[i]=false;
            }
        }
    }
}

int main(){
    int start;
    int end;
    cout<<"enter the start value"<<endl;
    cin>>start;
    cout<<"enter the end value"<<endl;
    cin>>end;
    if(start>end){
        swap(start,end);
    }
    if(end<0){
        cout<<"invalid input"<<endl;
        return 0;
    }
    vector<bool>prime(end+1,true);
    if(end>=0){
        prime[0]=false;
    }
    if(end>=1){
        prime[1]=false;
    }
    seive(prime,end);
    cout<<"prime numbers between "<<start<<" and "<<end<<" are: "<<endl;
    for(int i=start;i<=end;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
}

// 1.  2 to 10   #2 3 5 7
// 2.  2 to 7 prime range   #2 3 5 7
// 3.  4 to 20 non-prime range  #5 7 11 13 17 19
// 4.  13 1nd 13 equal and prime  #13
// 5.  14 and 14 equal and non prime #
// 6.  11 and 2 reverse the order #2 3 5 7 11
// 7.  -3 and 2 negative range #2
// 8.  -8 and -7  both negative numbers #invalid input