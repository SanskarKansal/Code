#include<bits/stdc++.h>
using namespace std;

int indexsearch(int start,int end,int val,vector<int>& a){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==val){
            return mid;
        }
        
        if(a[start]<=a[mid]){
            if(val>=a[start] && val<a[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{ 
            if(val>a[mid] && val<=a[end]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int element;
        cin>>element;
        cout<<indexsearch(0,n-1,element,a)<<endl;
    }
    return 0;
}

/*
10
7
1 2 3 4 5 6 7
4
7
4 5 6 7 1 2 3
2
7
4 5 6 7 1 2 3
4
7
4 5 6 7 1 2 3
6
7
4 5 6 7 1 2 3
10
7
4 5 6 7 1 2 3
8
7
4 5 6 7 1 2 3
0
1
100
100
7
7 8 9 1 2 3 4
2
7
7 8 9 1 2 3 4
5

#
3
4
0
2
2
-1
0
3
3
-1

*/