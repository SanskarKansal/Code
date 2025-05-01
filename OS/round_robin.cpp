#include<bits/stdc++.h>
using namespace std;

void Time(int processes[], int n, int bt[], int round[], int wt[], int tat[]) {
    int total_wt = 0, total_tat = 0;
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "Processes  " <<" round taken  "<<"  Burst time  "<< "Waiting time  " << "Turn around time"<<endl;
    for(int i=0;i<n;i++){
        cout << "   " << processes[i] << "\t\t" << round[i] << "\t\t" << bt[i]
             << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / n;
    cout << "\nAverage turnaround time = " << (float)total_tat / n << endl;
}

int main() {
    int processes[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {3, 17, 6, 9, 13, 11};
    int time_quantum = 5;

    int remaining_bt[n], completion[n] = {0}, round[n] = {0};
    for (int i = 0; i < n; i++)
        remaining_bt[i] = burst_time[i];

    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);

    int t = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        round[i]++;
        if (remaining_bt[i] <= time_quantum) {
            t += remaining_bt[i];
            completion[i] = t;
            remaining_bt[i] = 0;
        } else {
            t += time_quantum;
            remaining_bt[i] -= time_quantum;
            q.push(i);
        }
    }

    int wt[n], tat[n];
    for(int i = 0; i < n; i++) {
        tat[i] = completion[i];
        wt[i] = tat[i] - burst_time[i];
    }

    Time(processes, n, burst_time, round, wt, tat);

    return 0;
}
