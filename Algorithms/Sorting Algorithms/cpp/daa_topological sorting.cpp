#include <bits/stdc++.h>
using namespace std;
class Graph {
    int v;
    list<int>* adj;
public:
    Graph(int v);
    void addEdge(int u, int w);
    void topologicalSort_recur(int u, bool visited[], stack<int>& Stack);
    void topologicalSort();
};
Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}
void Graph::addEdge(int u, int w)
{
    adj[u].push_back(w);
}
void Graph::topologicalSort_recur(int v, bool visited[], stack<int>& Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (visited[*i] == false)
            topologicalSort_recur(*i, visited, Stack);
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            topologicalSort_recur(i, visited, Stack);
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Topological Sort of the given graph:\n";
    g.topologicalSort();
    return 0;
}
