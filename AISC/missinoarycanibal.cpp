#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct State {
    int leftM, leftC, boat;
    vector<string> moves;
};

bool isValid(int m, int c) {
    if (m < 0 || c < 0 || m > 3 || c > 3) return false;
    if (m > 0 && m < c) return false;
    if ((3 - m) > 0 && (3 - m) < (3 - c)) return false;
    return true;
}

vector<pair<int, int>> possibleMoves = {{1,0},{0,1},{1,1},{2,0},{0,2}};

int main() {
    queue<State> q;
    set<tuple<int,int,int>> vis;
    q.push({3,3,1,{}});
    vis.insert({3,3,1});
    while (!q.empty()) {
        State s = q.front();
        q.pop();
        if (s.leftM == 0 && s.leftC == 0 && s.boat == 0) {
            for (auto &move : s.moves) cout << move << endl;
            return 0;
        }
        for (auto [m,c] : possibleMoves) {
            int newM = s.leftM, newC = s.leftC, newBoat = s.boat ^ 1;
            string direction = (s.boat ? "Left -> Right" : "Right -> Left");
            if (s.boat) {
                newM -= m;
                newC -= c;
            } else {
                newM += m;
                newC += c;
            }
            if (isValid(newM,newC) && vis.find({newM,newC,newBoat}) == vis.end()) {
                vis.insert({newM,newC,newBoat});
                vector<string> newMoves = s.moves;
                newMoves.push_back("Move "+to_string(m)+"M "+to_string(c)+"C : "+direction);
                q.push({newM,newC,newBoat,newMoves});
            }
        }
    }
}
