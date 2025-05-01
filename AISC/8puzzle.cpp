#include <iostream>
#include <vector>
using namespace std;
const int N = 3;

struct State {
    vector<vector<int>> board;
    int x, y;
};

vector<State> path;
vector<pair<int, int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };

bool isGoal(State s) {
    int cnt = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i == N-1 && j == N-1) {
                if (s.board[i][j] != 0) return false;
            }
            else if (s.board[i][j] != cnt++) return false;
    return true;
}

bool isVisited(State s) {
    for (auto st : path) {
        if (st.board == s.board)
            return true;
    }
    return false;
}

void printBoard(State s) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << s.board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solve(State current) {
    path.push_back(current);
    if (isGoal(current)) {
        return true;
    }
    for (auto dir : directions) {
        int newX = current.x + dir.first;
        int newY = current.y + dir.second;
        if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
            State next = current;
            swap(next.board[current.x][current.y], next.board[newX][newY]);
            next.x = newX;
            next.y = newY;
            if (!isVisited(next)) {
                if (solve(next)) {
                    return true;
                }
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    State start;
    start.board = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };
    start.x = 1;
    start.y = 1; 
    if (solve(start)) {
        cout << "Solution Path:\n";
        for (auto s : path) {
            printBoard(s);
        }
    } 
    else {
        cout << "No solution found.\n";
    }
    return 0;
}
