#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int startNode, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse all neighbors of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
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

    cout << "BFS starting from node 0: ";
    BFS(0, adjList, visited);

    return 0;
}
