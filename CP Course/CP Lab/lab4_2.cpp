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

void partition(Node* head, Node* pivot, Node** left, Node** right) {
    while (head != nullptr) {
        Node* next = head->next;
        if (head != pivot) {
            if (head->val < pivot->val) {
                head->next = *left;
                *left = head;
            } else {
                head->next = *right;
                *right = head;
            }
        }
        head = next;
    }
}

Node* getTail(Node* head) {
    while (head && head->next) head = head->next;
    return head;
}

Node* quickSort(Node* head) {
    if (!head || !head->next) return head;

    Node* pivot = getTail(head);
    Node *left = nullptr, *right = nullptr;

    partition(head, pivot, &left, &right);

    left = quickSort(left);
    right = quickSort(right);

    Node* result = nullptr;
    Node* tail = nullptr;

    if (left) {
        result = left;
        tail = left;
        while (tail->next) tail = tail->next;
        tail->next = pivot;
    } else {
        result = pivot;
    }

    pivot->next = right;
    return result;
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
            Node* newNode = new Node(val);
            cin >> newNode->val;
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        head = quickSort(head);
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
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