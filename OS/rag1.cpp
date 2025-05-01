#include<bits/stdc++.h>
using namespace std;
class ResourceAllocationGraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
public:
    ResourceAllocationGraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
    }
    void displayMatrix() {
        cout << "\nAdjacency Matrix Representation:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int processes, resources;
    cout << "Enter number of processes: ";
    cin >> processes;
    cout << "Enter number of resources: ";
    cin >> resources;
    
    int totalVertices = processes + resources;
    ResourceAllocationGraphMatrix rag(totalVertices);

    cout << "Enter the number of allocated edges: ";
    int allocEdges;
    cin >> allocEdges;
    cout << "Enter allocated edges (Process -> Resource):\n";
    for (int i = 0; i < allocEdges; i++) {
        int p, r;
        cin >> p >> r;
        rag.addEdge(p, processes + r);
    }

    cout << "Enter the number of request edges: ";
    int reqEdges;
    cin >> reqEdges;
    cout << "Enter requested edges (Resource -> Process):\n";
    for (int i = 0; i < reqEdges; i++) {
        int r, p;
        cin >> r >> p;
        rag.addEdge(processes + r, p);
    }
    rag.displayMatrix();
    
    return 0;
}
