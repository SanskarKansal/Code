#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq;
    string name;
    Node* left;
    Node* right;
    string code;
    
    Node(int f, string n){
        freq=f;
        name=n;
        left=nullptr;
        right=nullptr;
        code="";
    }
};

struct Compare {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void formtree(priority_queue<Node*, vector<Node*>, Compare>& pq) {
    while (pq.size() > 1) {
        Node* node1 = pq.top(); 
        pq.pop();
        Node* node2 = pq.top(); 
        pq.pop();
        Node* node = new Node(node1->freq + node2->freq, node1->name +'@'+ node2->name);
        node->left = node1;
        node->right = node2;
        pq.push(node);
    }
}

void formcode(Node* root, string s) {
    if (!root){
        return;
    }
    if (!root->left && !root->right) {
        root->code = s;
    }
    else {
        formcode(root->left, s + '0');
        formcode(root->right, s + '1');
    }
}

void input(priority_queue<Node*, vector<Node*>, Compare>& pq, vector<Node*>& allnodes) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int freq;
        cin >> name >> freq;
        Node* node = new Node(freq, name);
        pq.push(node);
        allnodes.push_back(node);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        vector<Node*> allnodes;
        
        input(pq, allnodes);
        formtree(pq);
        
        Node* root = pq.top();
        formcode(root, "");
        
        for (auto node : allnodes) {
            cout << node->name << " " << node->code <<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
5
5
A 5
B 9
C 12
D 13
E 16
4
A 10
B 15
C 30
D 40
6
X 5
Y 9
Z 12
P 7
Q 14
R 10
4
A 7
B 3
C 6
D 9
3
W 1
V 4
U 7
#
A 000 B 01 C 10 D 11 E 111
A 0 B 10 C 110 D 111
X 000 Y 001 Z 01 P 100 Q 101 R 11
A 00 B 10 C 01 D 11
W 0 V 10 U 11

*/