#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Function to perform topological sort using Kahn's algorithm
void topologicalSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    
    // Step 1: Compute in-degree of all vertices
    for (int i = 0; i < V; i++) {
        for (int u : adj[i]) {
            inDegree[u]++;
        }
    }
    
    // Step 2: Initialize the queue with all vertices with 0 in-degree
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Perform BFS and collect topological order using a stack
    stack<int> topoStack;
    int count = 0; // Counter to check if the graph is a DAG (no cycle)

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoStack.push(node); // Store node in topological sort

        // Reduce in-degree of neighboring nodes
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }

        count++;
    }

    // If count != V, the graph has a cycle
    if (count != V) {
        cout << "Graph contains a cycle. Topological sort not possible." << endl;
        return;
    }

    // Step 4: Print topological sort (stack will give reverse order)
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

    topologicalSortKahn(V, adj);

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
// Topological Sort: 4 5 2 3 1 0
