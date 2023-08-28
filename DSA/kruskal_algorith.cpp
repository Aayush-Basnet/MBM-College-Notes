#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V, E;
    vector<pair<int, pair<int, int> > > edges;
public:
    Graph(int vertices, int edges) : V(vertices), E(edges) {}
    void addEdge(int u, int v, int weight) {
        edges.push_back(make_pair(weight, make_pair(u, v)));
    }
    int kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(V);
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }
        int mstWeight = 0;
        int numEdges = 0;
        for (vector<pair<int, pair<int, int> > >::iterator it = edges.begin(); it != edges.end(); ++it) {
            int weight = it->first;
            int u = it->second.first;
            int v = it->second.second;
            int parentU = parent[u];
            int parentV = parent[v];
            if (parentU != parentV) {
                mstWeight += weight;
                ++numEdges;
                for (int i = 0; i < V; ++i) {
                    if (parent[i] == parentV) {
                        parent[i] = parentU; } 
                }
            }
            if (numEdges == V - 1) {
                break; }
        }
        return mstWeight; }
};
int main() {
    int V = 5, E = 7;
    Graph graph(V, E);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);
    int mstWeight = graph.kruskalMST();
    cout << "Weight of Minimum Spanning Tree using Kruskal's Algorithm: " << mstWeight << endl;
    return 0; }

