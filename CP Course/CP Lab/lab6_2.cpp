#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n,int i,int j){
    int left=~0;
    left=left<<(j+1);
    if(j>=31){
        left=0;
    }
    int right=(1<<i)-1;
    int num=left | right;
    m= m & num;
    n=n<<i;
    m=m | n;
    return m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int i,j;
        cin>>i>>j;
        int ans=solve(m,n,i,j);
        cout<<ans<<endl;
    }
}

/*
6
16384 19 2 6
16388 19 2 6
16388 19 0 4
16403 19 0 4
16384 1 0 0
511 5 6 8
#16460
#16460
#16403
#16403
#16385
#383
*/