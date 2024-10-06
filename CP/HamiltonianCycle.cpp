#include <iostream>
#include <vector>

using namespace std;

// Number of vertices in the graph
#define N 5

// Function to print the Hamiltonian Cycle
void printCycle(const vector<int>& path) {
    for (int vertex : path)
        cout << vertex << " ";
    // To show it's a cycle, print the first vertex again
    cout << path[0] << endl;
}

// Utility function to check if the current vertex can be added to the Hamiltonian Cycle
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& path, int pos) {
    // Check if the current vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the current vertex has already been included in the path
    for (int vertex : path)
        if (vertex == v)
            return false;

    return true;
}

// Recursive function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Base case: If all vertices are included in the path
    if (pos == N) {
        // And if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle
    for (int v = 1; v < N; v++) { // Starting from 1 since 0 is the starting vertex
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack if adding vertex v doesn't lead to a solution
            path[pos] = -1;
        }
    }

    // If no vertex can be added to the Hamiltonian Cycle
    return false;
}

// Main function to solve the Hamiltonian Cycle problem
bool hamCycle(const vector<vector<int>>& graph) {
    vector<int> path(N, -1);

    // Let us start at vertex 0
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists\n";
        return false;
    }

    printCycle(path);
    return true;
}

int main() {
    /* Let us create the following graph
        (0)--(1)--(2)
         |   / \   |
         |  /   \  |
         | /     \ |
        (3)-------(4)
    */

    vector<vector<int>> graph1 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    cout << "Graph 1:\n";
    hamCycle(graph1);

    // Another graph without Hamiltonian Cycle
    vector<vector<int>> graph2 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };

    cout << "\nGraph 2:\n";
    hamCycle(graph2);

    return 0;
}
