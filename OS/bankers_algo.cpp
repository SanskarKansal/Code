#include<bits/stdc++.h>
using namespace std;

const int P = 5;
const int R = 3; 
void calculateSafeSequence(int available[], int max[][R], int allocation[][R]) {
    int need[P][R], work[R], safeSequence[P];
    bool finish[P] = {false};
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    for (int i = 0; i < R; i++)
        work[i] = available[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == R) { 
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is in an unsafe state." << endl;
            return;
        }
    }
    cout << "Safe Sequence: ";
    for (int i = 0; i < P; i++)
        cout << "P" << safeSequence[i] << " ";
    cout << endl;
}

int main() {
    int available[R] = {3, 3, 2};
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {6, 0, 2},
        {2, 2, 1},
        {2, 3, 2}
    };

    calculateSafeSequence(available, max, allocation);
    return 0;
}
