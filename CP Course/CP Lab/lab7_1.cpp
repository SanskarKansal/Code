#include <bits/stdc++.h>
using namespace std;

int partition(int p, int r, vector<int> &arr, int pivot)
{
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else if (arr[j] == pivot)
        {
            int temp = arr[j];
            arr[j] = arr[r];
            arr[r] = temp;
            j--;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

int medianOfmedian(int p, int r, vector<int> &arr, int k)
{
    if (arr.size() == 1){
        return arr[0];
    }
    vector<int> temp;
    for (int i = p; i <= r; i = i + 5)
    {
        if (i + 5 < arr.size())
        {
            sort(arr.begin() + i, arr.begin() + i + 5);
        }
        else
        {
            sort(arr.begin() + i, arr.end());
        }
        int j = min(i + 5, r);
        int median = i + (j - i) / 2;
        temp.push_back(arr[median]);
    }
    return medianOfmedian(0, temp.size() - 1, temp, k);
}

void solve(int p, int r, vector<int> &arr, int k)
{
    if (p <= r)
    {
        int median = medianOfmedian(p, r, arr, k);
        int q = partition(p, r, arr, median);
        if (q == k - 1)
        {
            cout << arr[q] << endl;
            return;
        }
        else if (q > k - 1)
        {
            solve(p, q - 1, arr, k);
        }
        else
        {
            solve(q + 1, r, arr, k);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        solve(0, n - 1, arr, k);
    }
}
/*
6
5
5 2 1 6 3
3
7
12 3 5 7 19 1 8
4
6
1 2 3 4 5 6
2
7
5 3 7 1 4 8 6
5
6
12 3 5 7 19 1
2
8
10 4 9 2 6 1 5 7
6
#
3
5
2
4
5
7
*/