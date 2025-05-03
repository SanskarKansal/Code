#include<bits/stdc++.h>
using namespace std;

struct Node {
    int vertex;
    int key;
};

class minheap {
public:
    vector<Node> heap;
    vector<int> pos;
    int size;

    minheap(int V) {
        size = V;
        heap.resize(V);
        pos.resize(V);
    }

    void swapNodes(int i, int j) {
        swap(heap[i], heap[j]);
        pos[heap[i].vertex] = i;
        pos[heap[j].vertex] = j;
    }

    void heapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1, right = 2 * idx + 2;

        if (left < size && heap[left].key < heap[smallest].key)
            smallest = left;
        if (right < size && heap[right].key < heap[smallest].key)
            smallest = right;
        
        if (smallest != idx) {
            swapNodes(idx, smallest);
            heapify(smallest);
        }
    }

    Node extractMin() {
        if (size == 0) return {-1, -1};
        Node root = heap[0];
        heap[0] = heap[size - 1];
        pos[heap[0].vertex] = 0;
        size--;
        heapify(0);
        return root;
    }

    void decreaseKey(int v, int key) {
        int i = pos[v];
        heap[i].key = key;
        while (i > 0 && heap[i].key < heap[(i - 1) / 2].key) {
            swapNodes(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    bool isfound(int v) {
        return pos[v] < size;
    }
};

void primMST(vector<vector<pair<int, int>>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> contains(V, false);
    minheap minheap(V);

    for (int v = 0; v < V; v++) {
        minheap.heap[v] = {v, key[v]};
        minheap.pos[v] = v;
    }

    key[0] = 0;
    minheap.decreaseKey(0, 0);

    while (minheap.size > 0) {
        Node minNode = minheap.extractMin();
        int u = minNode.vertex;
        contains[u] = true;

        for (auto &[v, weight] : graph[u]) {
            if (!contains[v] && minheap.isfound(v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                minheap.decreaseKey(v, weight);
            }
        }
    }
    for (int i = 1; i < V; i++){    
        cout << parent[i] << " - " << i << " " << key[i] << "\n";
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int V;
        cin>>V;
        vector<vector<pair<int, int>>> graph(V);
        int e;
        cin>>e;
        while(e--){
            int u;
            cin>>u;
            int v;
            cin>>v;
            int w;
            cin>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        primMST(graph, V);
    }
    return 0;
}

/*
5
4
5
0 1 10
0 2 20
1 2 5
1 3 10
2 3 5
5
4
0 1 5
0 2 10
0 3 20
0 4 25
4
4
0 1 10
1 2 5
2 3 15
3 0 20
6
5
0 1 10
0 2 20
1 3 30
3 4 5
4 5 10
4
6
0 1 10
0 2 5
0 3 15
1 2 10
1 3 25
2 3 20

#
0 - 1 10
1 - 2 5
2 - 3 5
0 - 1 5
0 - 2 10
0 - 3 20
0 - 4 25
0 - 1 10
1 - 2 5
2 - 3 15
0 - 1 10
1 - 3 30
3 - 4 5
4 - 5 10
0 - 1 10
0 - 2 5
1 - 2 10

*/