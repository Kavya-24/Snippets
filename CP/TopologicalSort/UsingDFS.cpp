#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and store the topological sort in a stack
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    // Visit all the neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, topoStack);
        }
    }

    // After visiting all neighbors, push the current node to the stack
    topoStack.push(node);
}

// Function to perform topological sort using DFS
void topologicalSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> topoStack;

    // Perform DFS from all unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, topoStack);
        }
    }

    // Print topological sort (stack will give reverse order)
    cout << "Topological Sort: ";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (u v) where u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSortDFS(V, adj);

    return 0;
}

// Input:
// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1

// Output:
// Topological Sort: 5 4 2 3 1 0
