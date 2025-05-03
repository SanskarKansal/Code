#include<bits/stdc++.h>
using namespace std;

void input(int n, vector<int>& arr) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void heapify(vector<int>& a, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void mergeHeaps(vector<int>& a, vector<int>& b) {
    a.insert(a.end(), b.begin(), b.end());
    int size = a.size();
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(a, i, size);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        vector<int> a(m);
        input(m, a);
        cin >> n;
        vector<int> b(n);
        input(n, b);
        
        mergeHeaps(a, b);
        
        for (int val : a) cout << val << " ";
        cout << "\n";
    }
    return 0;
}


/*
5
3
10 5 3
2
7 6
4
20 18 15 10
3
25 12 5
5
40 30 20 10 5
4
35 25 15 10
2
100 50
2
75 25
1
100
1
75
#
10 7 3 5 6 
25 20 15 10 18 12 5 
40 30 35 15 5 20 25 10 10
100 50 75 25
100 75
*/