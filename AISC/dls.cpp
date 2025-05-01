#include <bits/stdc++.h>
using namespace std;

const int success = 0;
const int cutoff = 1;
const int failure = 2;

int dlsRec(vector<vector<int>> &grid, vector<int> initial_State, vector<int> target_State, int depth_Limit, vector<vector<int>> &path, int dRow[], int dCol[], vector<vector<bool>> &visited)
{
    if (initial_State == target_State)
    {
        path.push_back(initial_State);
        return success;
    }
    if (depth_Limit == 0)
    {
        return cutoff;
    }
    visited[initial_State[0]][initial_State[1]] = true;
    int result = failure;
    for (int i = 0; i < 4; i++){
        int nRow = dRow[i] + initial_State[0];
        int nCol = dCol[i] + initial_State[1];
        if (nRow >= 0 && nCol >= 0 && nRow < grid.size() && nCol < grid[0].size() && grid[nRow][nCol] != 1 && !visited[nRow][nCol]){
            vector<int> child = {nRow, nCol};
            int childResult = dlsRec(grid, child, target_State, depth_Limit - 1, path, dRow, dCol, visited);
            if (childResult == success)
            {
                path.push_back(initial_State);
                return success;
            }
            if (childResult == cutoff)
            {
                result = cutoff;
            }
        }
    }
    visited[initial_State[0]][initial_State[1]] = false;
    return result;
}

void dls(vector<vector<int>> grid, vector<int> target_State, int depth_Limit, vector<vector<int>> &path){
    vector<int> initial_State = {0, 0};
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int dRow[] = {0, 1, 0, -1};
    int dCol[] = {-1, 0, 1, 0};
    int result = dlsRec(grid, initial_State, target_State, depth_Limit, path, dRow, dCol, visited);
    if (result == failure)
    {
        cout << "Path not possible" << endl;
    }
    else if (result == cutoff)
    {
        cout << "Path not found within depth limit" << endl;
    }
    else
    {
        reverse(path.begin(), path.end());
    }
}

int main(){
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0}};
    vector<vector<int>> path;
    vector<int> target = {4, 4};
    int depth_Limit = 10;

    dls(grid, target, depth_Limit, path);
    if (!path.empty())
    {
        cout << "Path found: " << endl;
        for (const auto &state : path)
        {
            cout << "{ " << state[0] << ", " << state[1] << " }" << endl;
        }
    }

    return 0;
}
