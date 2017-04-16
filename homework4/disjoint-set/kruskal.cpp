#include <iostream>
#include <vector>
#include <algorithm>
#include "disjoint_set.h"

using namespace std;

typedef tuple<unsigned, unsigned, int> edge; // < vertex, vertex, weight >

struct graph {
    int V, E;
    vector<edge> edges;

    graph(int V_count) {
        V = V_count;
        E = 0;
    }

    void add_edge(unsigned u, unsigned v, int w) {
        edges.push_back( edge(u, v, w) );
        E++;
    }

    int kruskal() {
        int total_weight = 0;
        disjoint_set *ds = new disjoint_set(V);
        sort(edges.begin(), edges.end());
        
        for (size_t i = 0; i < edges.size(); i++) {
            int u = get<0>(edges[i]);
            int v = get<1>(edges[i]);
            
            if (!ds->is_same_set(u, v)) {
                cout << u << " - " << v << endl;
                total_weight += get<2>(edges[i]);
                ds->uni(u, v);
            }
        }
        return total_weight;
    }
};

int main() {
    int V = 9;
    graph g(V);
    g.add_edge(0, 1, -4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, -5);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, -4);
    g.add_edge(4, 5, -10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, -6);
    g.add_edge(7, 8, 7);

    cout << "Edges of MST:" << endl;
    int MST_weight = g.kruskal();

    cout << endl << "Weight of MST: " << MST_weight << endl;

    return 0;
}
