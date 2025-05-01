#include<bits/stdc++.h>
using namespace std;

int objectivefunction(int val){
    return val*val-4*val+4;
}

int hillclimbing(int start,int step,int maxitr){
    int cur=start;
    int best=cur;
    for(int i=0;i<maxitr;i++){
        int neigh1=cur+step;
        int neigh2=cur-step;
        int bestval=objectivefunction(best);
        int neighval1=objectivefunction(neigh1);
        int neighval2=objectivefunction(neigh2);
        if(neighval1>bestval){
            best=neigh1;
            if(neighval2>bestval){
                best=neigh2;
            }
        }
        if(best==cur){
            break;
        }
        cur=best;
    }
    return cur;
}

int main(){
    int start;
    cin>>start;
    int step=1;
    int iterations=1000;
    cout<<hillclimbing(start,step,iterations);
}