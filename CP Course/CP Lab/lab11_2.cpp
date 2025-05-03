#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

bool dfs(int v, vector<Node*>& adjlist, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;
    
    Node* temp = adjlist[v]; 
    while (temp) {
        int neighbor = temp->val;
        if (!visited[neighbor] && dfs(neighbor, adjlist, visited, recStack))
            return true;
        else if (recStack[neighbor]) 
            return true;
        temp = temp->next;
    }
    
    recStack[v] = false;
    return false;
}

bool isCycle(int V, vector<Node*>& adjlist) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(i, adjlist, visited, recStack)) 
            return true;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V;
        cin >> V;
        vector<Node*> adjlist(V, nullptr); 
        for (int i = 0; i < V; i++) {
            int E;
            cin >> E;
            Node* head = nullptr;
            Node* tail = nullptr;
            for (int j = 0; j < E; j++) {
                int x;
                cin >> x;
                Node* newNode = new Node(x);
                
                if (!head) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            adjlist[i] = head; 
        }
        cout << isCycle(V, adjlist)<< endl;
    }
    return 0;
}


/*
6
1 1
2 2 5
1 3
1 4
2 0 1
0
5
1 1
1 2
1 3
1 4
0
5
1 1
2 3 4
0
1 4
1 2

#
1 
0
0
1
0
1
*/