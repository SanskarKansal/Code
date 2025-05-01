#include <bits/stdc++.h>
using namespace std;

struct Process {
    int idprocess;
    int at;
    int bt; 
    int tat; 
    int wt; 
    int ct; 
    int priority; 
};

void calculatePriorityScheduling(vector<Process>& p, int n) {
    int currenttime = 0, completed = 0;
    vector<bool> isCompleted(n, false);
    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currenttime && !isCompleted[i]) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
            }
        }
        currenttime += p[idx].bt;
        p[idx].ct = currenttime;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        isCompleted[idx] = true;
        completed++;
    }
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> p(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time, burst time and priority of process " << i + 1 << ": ";
        p[i].idprocess = i + 1;
        cin >> p[i].at >> p[i].bt >> p[i].priority;
    }
    calculatePriorityScheduling(p, n);
    cout << "P\tAT\tBT\tPriority\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].idprocess << "\t";
        cout << p[i].at << "\t";
        cout << p[i].bt << "\t";
        cout << p[i].priority << "\t\t";
        cout << p[i].ct << "\t";
        cout << p[i].tat << "\t";
        cout << p[i].wt << "\t" << endl;
    }
    return 0;
}
