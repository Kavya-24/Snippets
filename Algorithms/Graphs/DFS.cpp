#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[node] = true;
    cout << node << " ";

    // Traverse all the neighbors of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
    }
}

int main() {
    int numNodes = 5; // Number of nodes in the graph
    vector<vector<int>> adjList(numNodes);
    vector<bool> visited(numNodes, false);

    // Example adjacency list (undirected graph)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1};
    adjList[4] = {1, 2};

    cout << "DFS starting from node 0: ";
    DFS(0, adjList, visited);

    return 0;
}
