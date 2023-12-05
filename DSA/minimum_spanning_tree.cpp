#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;
class Graph {
private:
    int V;
    vector<vector<pair<int, int> > > adj;
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); }
    void primMST() {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        pq.push(make_pair(0, 0));
        key[0] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
           for (vector<pair<int, int> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u; }
            }
        }
        cout << "Edges in Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << endl;
        }
    }
};

int main() {
    int V = 5;
    Graph graph(V);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
    graph.primMST();
    return 0;
}

