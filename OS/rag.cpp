#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class ResourceAllocationGraph {
    unordered_map<int, vector<int>> graph;
    vector<bool> visited, inStack;
    int processes, resources;

    bool dfs(int node) {
        if (!visited[node]) {
            visited[node] = inStack[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor] && dfs(neighbor)) return true;
                if (inStack[neighbor]) return true;
            }
        }
        inStack[node] = false;
        return false;
    }

    ResourceAllocationGraph(int p, int r) : processes(p), resources(r) {}

    void addAllocation(int process, int resource) {
        graph[resource + processes].push_back(process);
    }

    void addRequest(int process, int resource) {
        graph[process].push_back(resource + processes);
    }

    bool hasDeadlock() {
        visited.assign(processes + resources, false);
        inStack.assign(processes + resources, false);
        for (int i = 0; i < processes + resources; i++) {
            if (!visited[i] && dfs(i)) return true;
        }
        return false;
    }
};

int main() {
    int pr, res;
    cin >> pr >> res;
    ResourceAllocationGraph rag(pr, res);
    int alloc;
    cin >> alloc;
    for (int i = 0; i < alloc; i++) {
        int process, resource;
        cin >> process >> resource;
        rag.addAllocation(process, resource);
    }
    int req;
    cin >> req;
    for (int i = 0; i < req; i++) {
        int process, resource;
        cin >> process >> resource;
        rag.addRequest(process, resource);
    }
    cout << (rag.hasDeadlock() ? "Deadlock Detected" : "No Deadlock") << endl;
    return 0;
}
