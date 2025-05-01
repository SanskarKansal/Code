#include<bits/stdc++.h>
using namespace std;

#define TOTAL_BLOCKS 50

class LinkedListAllocation {
    struct Block {
        int index;
        Block* next;
    };
    unordered_map<int, Block*> files;
public:
    bool allocate(int id, vector<int> blocks) {
        Block* head = nullptr, *tail = nullptr;
        for (int b : blocks) {
            Block* newBlock = new Block{b, nullptr};
            if (!head) head = tail = newBlock;
            else {
                tail->next = newBlock;
                tail = newBlock;
            }
        }
        files[id] = head;
        return true;
    }
    void display() {
        for (auto &[id, head] : files) {
            cout<<id<<" ";
            Block* temp = head;
            while (temp) {
                cout << temp->index << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    LinkedListAllocation lla;
    lla.allocate(1, {3, 7, 9, 11});
    lla.allocate(2, {5, 8, 10, 13});
    lla.allocate(4, {12, 17, 19, 22});
    lla.display();
    return 0;
}