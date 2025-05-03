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

Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* left = nullptr;
    Node* right = nullptr;
    split(head, &left, &right);
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
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
        head = mergeSort(head);
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