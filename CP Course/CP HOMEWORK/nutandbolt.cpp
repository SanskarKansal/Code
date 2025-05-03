#include <bits/stdc++.h>
using namespace std;

int partition(vector<char>& arr, int i, int j, char val) {
    int left = i;
    for (int r = i; r < j; r++) {
        if (arr[r] < val) {
            swap(arr[r], arr[left]);
            left++;
        } else if (arr[r] == val) {
            swap(arr[r], arr[j]);
            r--;
        }
    }
    swap(arr[left], arr[j]);
    return left;
}

void quickSort(vector<char>& nuts, vector<char>& bolts, int i, int j) {
    if (i < j) {
        char val = nuts[j];
        int mid = partition(bolts, i, j, val);
        int m = partition(nuts, i, j, bolts[mid]);
        quickSort(nuts, bolts, i, m - 1);
        quickSort(nuts, bolts, m + 1, j);
    }
}

void pairs(int len, vector<char>& nuts, vector<char>& bolts) {
    quickSort(nuts, bolts, 0, len - 1);
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int len;
        cin >> len;
        vector<char> nuts(len), bolts(len);
        for (int i = 0; i < len; i++){
            cin >> nuts[i];
        }
        for (int i = 0; i < len; i++){
            cin >> bolts[i];
        }
        pairs(len, nuts, bolts);
        for (int i = 0; i < len; i++){
            cout << nuts[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < len; i++){
            cout << bolts[i] << " ";
        }
        cout << endl;
    }
}
