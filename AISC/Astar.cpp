#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, g, h;
    Node* parent;
    Node(int x, int y, int g, int h, Node* p) : x(x), y(y), g(g), h(h), parent(p) {}
    int f() const { 
        return g + h; 
    }
};

struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

void AStar(int sx, int sy, int ex, int ey) {
    priority_queue<Node*, vector<Node*>, Compare> open;
    set<pair<int, int>> visited;
    open.push(new Node(sx, sy, 0, heuristic(sx, sy, ex, ey), nullptr));
    while (!open.empty()) {
        Node* cur = open.top(); 
        open.pop();
        if (cur->x == ex && cur->y == ey) {
            vector<pair<int, int>> path;
            while (cur) {
                path.push_back({cur->x, cur->y});
                cur = cur->parent;
            }
            reverse(path.begin(), path.end());
            for (auto p : path)
                cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
            return;
        }

        if (visited.count({cur->x, cur->y})) continue;
        visited.insert({cur->x, cur->y});

        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto [dx, dy] : dirs) {
            int nx = cur->x + dx, ny = cur->y + dy;
            if (nx >= 0 && ny >= 0 && !visited.count({nx, ny})) {
                int g = cur->g + 1;
                int h = heuristic(nx, ny, ex, ey);
                open.push(new Node(nx, ny, g, h, cur));
            }
        }
    }

    cout << "No path found\n";
}

int main() {
    int startX = 0, startY = 0, endX = 3, endY = 3;
    AStar(startX, startY, endX, endY);
    return 0;
}