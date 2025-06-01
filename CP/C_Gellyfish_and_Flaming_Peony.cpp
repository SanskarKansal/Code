#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<endl;
        }
        else{
            long long g=a[0];
            for(int i=1;i<n;i++){
                g=gcd(g,a[i]);
            }
            int count=0;
            for(int i=0;i<n;i++){
                if(a[i]==g){
                    count++;
                }
            }
            if(count>0){
                cout<<n-count<<endl;
            }
            else{
                queue<long long>q;
                unordered_set<long long>vis;
                int ans=-1;
                int count=1;
                sort(a.begin(),a.end());
                for(int i=0;i<n;i++){
                    if(i>0 && a[i]==a[i-1]){
                        continue;
                    }
                    q.push(a[i]);
                    vis.insert(a[i]);
                }
                while(!q.empty()){
                    long long s=q.size();
                    for(long long i=0;i<s;i++){
                        long long num=q.front();
                        q.pop();
                        for(int j=0;j<n;j++){
                            long long val=gcd(num,a[j]);
                            if(val==g){
                                ans=count;
                                break;
                            }
                            if(!vis.count(val)){
                                q.push(val);
                                vis.insert(val);
                            }
                        }
                        if(ans!=-1){
                            break;
                        }
                    }
                    if(ans!=-1){
                        break;
                    }
                    count++;
                }
                cout<<n-1+count<<endl;
            }
        }
    }
    return 0;
}
