#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int startNode, vector<vector<pair<int, int>>>& adjList, vector<int>& distances) {
    // Priority queue to store (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Skip if we found a better way to this node already
        if (currentDistance > distances[currentNode]) continue;

        // Check all neighbors of the current node
        for (auto& neighbor : adjList[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            int newDistance = currentDistance + weight;

            // If a shorter path to nextNode is found
            if (newDistance < distances[nextNode]) {
                distances[nextNode] = newDistance;
                pq.push({newDistance, nextNode});
            }
        }
    }
}

int main() {
    int numNodes = 5; // Number of nodes in the graph
    vector<vector<pair<int, int>>> adjList(numNodes);
    vector<int> distances(numNodes, INF);

    // Example adjacency list (directed graph with weights)
    adjList[0].push_back({1, 2});
    adjList[0].push_back({2, 4});
    adjList[1].push_back({2, 1});
    adjList[1].push_back({3, 7});
    adjList[2].push_back({4, 3});
    adjList[3].push_back({4, 1});

    int startNode = 0;
    dijkstra(startNode, adjList, distances);

    cout << "Shortest distances from node " << startNode << ":\n";
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": ";
        if (distances[i] == INF)
            cout << "Infinity\n";
        else
            cout << distances[i] << "\n";
    }

    return 0;
}
