#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int>&arr,int row,int col)
{
    for(int j=0;j<col;j++)
    {
        if(arr[j]==row||(arr[j]-row)==(j-col)||(arr[j]-row==col-j))
        {
            return false;
        }
    }
    return true;
}
void printBoard(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]==i)
            cout<<"Q";
            else
            cout<<".";
        }
        cout<<endl;
    }
    cout<<"\n";
}
void nextValue(int col,int n,vector<int>&arr)
{
    bool k=true;
    int s=arr[col]+1;
    for(int row=s;row<n;row++)
    {
        if(isValid(arr,row,col))
        {
            arr[col]=row;
            k=false;
            return;
        }
    }
    if(k){
        arr[col]=-1;
    }
}
void generalBacktrack(int col,vector<int>&arr,int n)
{
    while(1)
    {
        nextValue(col,n,arr);
        if(arr[col]==-1)
        {
            break;
        }
        if(col==n-1)
        {
            printBoard(arr);
        }
        else
        {
            generalBacktrack(col+1,arr,n);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,-1);
        generalBacktrack(0,arr,n);
        return 0;
    }
}
/*
2
1
4

#
Q

..Q.
Q...
...Q
.Q..

.Q..
...Q
Q...
..Q.
*/