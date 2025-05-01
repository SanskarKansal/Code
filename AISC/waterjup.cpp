#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
bool canMeasureWater(int x, int y, int target)
{
    set<pair<int, int>> visited; 
    stack<pair<int, int>> st;   

    st.push({0, 0});
    while (!st.empty())
    {
        auto state = st.top();
        int jug1 = state.first;
        int jug2 = state.second;
        st.pop();
        if (visited.find(state) != visited.end())
            continue;

        visited.insert(state);

        if (jug1 == target || jug2 == target || jug1 + jug2 == target)
        {
            return true;
        }

        st.push({x, jug2});

        st.push({jug1, y});

        st.push({max(0, jug1 - (y - jug2)), min(y, jug1 + jug2)});

        st.push({min(x, jug1 + jug2), max(0, jug2 - (x - jug1))});

        st.push({0, jug2});

        st.push({jug1, 0});
    }
    return false;
}
int main()
{
    int x = 5;
    int y = 4;
    int target = 2;
    cout << canMeasureWater(x, y, target);
    return 0;
}