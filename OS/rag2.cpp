#include <iostream>
#include <vector>
using namespace std;

class ResourceAllocationGraphMatrix {
private:
    int processes, resources;
    vector<vector<int>> adjMatrix;
    vector<int> resourceInstances;

public:
    ResourceAllocationGraphMatrix(int p, int r) {
        processes = p;
        resources = r;
        int totalVertices = p + r;
        adjMatrix.resize(totalVertices, vector<int>(totalVertices, 0));
        resourceInstances.resize(r, 0);
    }

    void setResourceInstances() {
        cout << "Enter instances for each resource: \n";
        for (int i = 0; i < resources; i++) {
            cout << "Resource " << i << ": ";
            cin >> resourceInstances[i];
        }
    }

    void addAllocationEdge(int p, int r) {
        if (resourceInstances[r] > 0) {
            adjMatrix[p][processes + r] += 1;
            resourceInstances[r]--;
        } else {
            cout << "Resource " << r << " has no available instances to allocate.\n";
        }
    }

    void addRequestEdge(int p, int r) {
        adjMatrix[processes + r][p] += 1;
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix Representation:" << endl;
        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix[i].size(); j++) {
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
    
    ResourceAllocationGraphMatrix rag(processes, resources);
    rag.setResourceInstances();

    cout << "Enter the number of allocated edges: ";
    int allocEdges;
    cin >> allocEdges;
    cout << "Enter allocated edges (Process -> Resource):\n";
    for (int i = 0; i < allocEdges; i++) {
        int p, r;
        cin >> p >> r;
        rag.addAllocationEdge(p, r);
    }

    cout << "Enter the number of request edges: ";
    int reqEdges;
    cin >> reqEdges;
    cout << "Enter requested edges (Resource -> Process):\n";
    for (int i = 0; i < reqEdges; i++) {
        int r, p;
        cin >> r >> p;
        rag.addRequestEdge(p, r);
    }
    
    rag.displayMatrix();
    
    return 0;
}
