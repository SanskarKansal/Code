#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

Node* insertionSort(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr;

    while (head) {
        Node* curr = head;
        head = head->next;
        if (!sorted || curr->val < sorted->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->val < curr->val){
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        head = insertionSort(head);
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}
/*
9
5
1 2 3 4 5
5
5 4 3 2 1
5
3 1 2 3 1
4
7 7 7 7
6
10 5 3 8 2 9
1
42
2
2 1
2
-1 -5
4
0 -2 3 -1

#
1 2 3 4 5
1 2 3 4 5
1 1 2 3 3
7 7 7 7
2 3 5 8 9 10
42
1 2
-5 -1
-2 -1 0 3


*/