#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int> > > adj;
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }
    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (vector<pair<int, int> >::const_iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v)); }
            }
        }
        cout << "Shortest distances from vertex " << start << ":" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << endl; }
    }
};
int main() {
    int V = 6;
    Graph graph(V);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 3);

    int startVertex = 0;
    cout << "Shortest path distances from vertex " << startVertex << " using Dijkstra's algorithm:" << endl;
    graph.dijkstra(startVertex);
    return 0;
}

