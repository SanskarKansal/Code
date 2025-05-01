#include<bits/stdc++.h>
using namespace std;

#define TOTAL_BLOCKS 50

class ContiguousAllocation {
    vector<int> disk;
public:
    ContiguousAllocation() {
        disk=vector<int>(TOTAL_BLOCKS, 0);
    }
    bool allocate(int start, int size) {
        if (start + size > TOTAL_BLOCKS) return false;
        for (int i = start; i < start + size; ++i) {
            if (disk[i] != 0) return false;
        }
        for (int i = start; i < start + size; ++i) {
            disk[i] = 1;
        }
        return true;
    }
    void display() {
        for (int i = 0; i < TOTAL_BLOCKS; ++i) {
            cout << disk[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ContiguousAllocation ca;
    ca.allocate(10, 9);
    ca.allocate(20, 5);
    ca.allocate(30, 5);
    ca.allocate(40, 5);
    ca.display();
    return 0;
}