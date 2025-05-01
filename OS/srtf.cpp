#include<bits/stdc++.h>
using namespace std;
struct Process{
    int idprocess;
    int at;
    int bt;
    int tat;
    int wt;
    int rt;
    int ct;
};

void calculateSRTF(vector<Process>& p,int n){
    int currenttime=0;
    int completed=0;
    while(completed<n){
        int idx=-1;
        int minn=INT_MAX;
        for(int i=0;i<n;i++){
            if(p[i].at<=currenttime && p[i].rt<minn && p[i].rt>0){
                minn=p[i].rt;
                idx=i;
            }
        }
        p[idx].rt--;
        currenttime++;
        if(p[idx].rt==0){
            completed++;
            p[idx].ct=currenttime;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
        }
    }
}

int main() {
    int n;
    vector<Process> p(n);
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time and burst time of process "<<i+1<<": ";
        p[i].idprocess=i;
        cin>>p[i].at;
        cin>>p[i].bt;
        p[i].rt=p[i].bt;    
    }
    calculateSRTF(p,n);
    cout<<"P\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].idprocess+1<<"\t";
        cout<<p[i].at<<"\t";
        cout<<p[i].bt<<"\t";
        cout<<p[i].ct<<"\t";
        cout<<p[i].tat<<"\t";
        cout<<p[i].wt<<"\t";
        cout<< endl;
    }
    return 0;
}