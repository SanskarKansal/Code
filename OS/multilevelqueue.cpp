#include <bits/stdc++.h>
using namespace std;

struct P {
    int id, at, bt, tat, wt, ct, py;
};
void exec(P& p, int& t) {
    if (t < p.at) t = p.at;
    p.ct = t + p.bt;
    p.tat = p.ct - p.at;
    p.wt = p.tat - p.bt;
    t = p.ct;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    vector<P> all(n), high, low;
    
    for (int i = 0; i < n; i++) {
        cin >> all[i].at >> all[i].bt >> all[i].py;
        all[i].id = i + 1;
        
        if (all[i].py < 5) high.push_back(all[i]);
        else low.push_back(all[i]);
    }
    
    int t = 0, done = 0;
    while (done < n) {
        bool ex = false;
        for (int i = 0; i < high.size(); i++) {
            if (high[i].at <= t) {
                exec(high[i], t);
                all[high[i].id - 1] = high[i];
                high.erase(high.begin() + i);
                done++;
                ex = true;
                break;
            }
        }
        if (!ex) {
            for (int i = 0; i < low.size(); i++) {
                if (!high.empty() && high.front().at <= t) break; 
                if (low[i].at <= t) {
                    exec(low[i], t);
                    all[low[i].id - 1] = low[i];
                    low.erase(low.begin() + i);
                    done++;
                    ex = true;
                    break;
                }
            }
        }
    } 
    
    sort(all.begin(), all.end(), [](P a, P b) { return a.id < b.id; });
    cout << "P\tAT\tBT\tPy\tCT\tTAT\tWT" << endl;
    for (auto& p : all) {
        cout << p.id << "\t" << p.at << "\t" << p.bt << "\t" << p.py << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\t" << endl;
    }
    return 0;
}
