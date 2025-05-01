#include <bits/stdc++.h>
using namespace std;
int objective_function(const vector<int>& solution, vector<vector<int>>& val) {
    int sum=0;
    for(int i=0;i<solution.size();i++){
        sum+=val[i][solution[i]];
    }
    return sum;
}
vector<vector<int>> get_neighbors(const vector<int>& solution ) {
    vector<vector<int>> neighbors;
    for (size_t i = 0; i < solution.size(); i++) {
        for (size_t j = i + 1; j < solution.size(); j++) {
            vector<int> neighbor = solution;
            swap(neighbor[i], neighbor[j]);
            neighbors.push_back(neighbor);
            swap(neighbor[i], neighbor[j]);
        }
    }
    return neighbors;
}
vector<int> tabu_search(const vector<int>& initial_solution, int max_iterations, int tabu_list_size, vector<vector<int>>& val) {
    vector<int> best_solution = initial_solution;
    vector<int> current_solution = initial_solution;
    set<vector<int>> tabu_list;
    for (int iter = 0; iter < max_iterations; iter++) {
        vector<vector<int>> neighbors = get_neighbors(current_solution);
        vector<int> best_neighbor;
        int best_neighbor_fitness = INT_MAX;
        for (const auto& neighbor : neighbors) {
            if (tabu_list.find(neighbor) == tabu_list.end()) {
                int neighbor_fitness = objective_function(neighbor,val);
                if (neighbor_fitness < best_neighbor_fitness) {
                    best_neighbor = neighbor;
                    best_neighbor_fitness = neighbor_fitness;
                }
            }
        }
        if (best_neighbor.empty()){
            break;
        }
        current_solution = best_neighbor;
        tabu_list.insert(best_neighbor);
        if (tabu_list.size() > tabu_list_size) {
            tabu_list.erase(tabu_list.begin());
        }
        if (best_neighbor_fitness < objective_function(best_solution,val)) {
            best_solution = best_neighbor;
        }
    }
    return best_solution;
}
int main() {
    vector<int> initial_solution = {0, 1, 2, 3, 4};
    vector<vector<int>>val={
        {9,2,7,8,6},
        {6,4,3,7,5},
        {5,8,1,8,4},
        {3,6,7,9,2},
        {8,4,5,6,3}
    };   
    int max_iterations = 50;
    int tabu_list_size = 10;
    vector<int> best_solution = tabu_search(initial_solution, max_iterations, tabu_list_size,val);
    cout << "Best solution:";
    for (int val : best_solution) {
        cout << val+1<<" ";
    }
    cout<<endl;
    cout << "Best solution fitness: " << objective_function(best_solution,val) << endl;
    return 0;
}