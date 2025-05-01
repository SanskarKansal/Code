#include <bits/stdc++.h>
using namespace std;

class TravelingSalesman
{
private:
    vector<vector<int>> distances;
    int numCities;

    int findShortestPath(int currentCity, vector<bool> &visited, int citiesVisited, int totalDistance)
    {
        if (citiesVisited == numCities)
        {
            return totalDistance + distances[currentCity][0];
        }
        int shortestPath = INT_MAX;
        for (int nextCity = 0; nextCity < numCities; nextCity++)
        {
            if (!visited[nextCity])
            {
                visited[nextCity] = true;

                int newPath = findShortestPath(nextCity, visited, citiesVisited + 1,totalDistance + distances[currentCity][nextCity]);

                shortestPath = min(shortestPath, newPath);
                visited[nextCity] = false;
            }
        }

        return shortestPath;
    }

public:
    int findRoute(vector<vector<int>> &distanceMatrix)
    {
        distances = distanceMatrix;
        numCities = distances.size();
        vector<bool> visited(numCities, false);
        visited[0] = true;
        return findShortestPath(0, visited, 1, 0);
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    TravelingSalesman tsp;
    int shortestRoute = tsp.findRoute(distances);

    cout << "Shortest possible route length: " << shortestRoute << endl;

    return 0;
}