#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>val(n);
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        int count=0;
        sort(val.begin(),val.end());
        int left=0;
        int right=n-1;
        while(left<right){
            if(val[left]+val[right]==k){
                count++;
                left++;
                right--;
            }
            else if(val[left]+val[right]<k){
                left++;
            }
            else{
                right--;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
