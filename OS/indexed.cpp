#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> f(50, 0);
    vector<int> index(50);
    int i, n, ind;

    cout << "Enter the index block: ";
    cin >> ind;

    if (f[ind] == 1) {
        cout << ind << " index is already allocated.\n";
        return 0;
    }

    cout << "Enter number of blocks needed for the index " << ind << ": ";
    cin >> n;

    int count = 0;
    cout << "Enter the block numbers:\n";
    for (i = 0; i < n; i++) {
        cin >> index[i];
        if (f[index[i]] == 0)
            count++;
    }

    if (count == n) {
        for (i = 0; i < n; i++)
            f[index[i]] = 1;

        f[ind] = 1;

        cout << "Allocated\n";
        cout << "File Indexed:\n";
        for (i = 0; i < n; i++)
            cout << ind << " --------> " << index[i] << endl;
    } else {
        cout << "Some blocks are already allocated. Please re-run the program.\n";
    }

    return 0;
}
