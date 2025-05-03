#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& val, int i, int j) {
    int pivot = val[j];
    int left = i - 1;
    for (int r = i; r <= j - 1; r++) {
        if (val[r] <= val[j]) {
            left++;
            swap(val[left], val[r]);
        }
    }
    swap(val[left + 1], val[j]);
    return left + 1;
}

void quickSort(vector<int>& val, int i, int j, int k) {
    if (i < j) {
        int m = partition(val, i, j);
        if (m == k - 1) return;
        if (m > k - 1) {
            quickSort(val, i, m - 1, k);
        } else {
            quickSort(val, m + 1, j, k);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        quickSort(val, 0, n - 1, k);
        cout << val[k - 1] << endl;
    }
    return 0;
}
/*
7
5 3
2 5 8 1 10
6 4
-1 4 7 2 0 5
7 1
-1 4 7 2 0 5 9
5 5
-1 4 7 2 5
5 2
1 2 3 4 5
6 3
8 6 4 2 1 -5
1 1
1
#
5
4
-1
7
2
2
1
*/