#include <iostream>
#include "priorityqueue.cpp"
#include <vector>
#include <random>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

struct node {
  vector<struct node> adj;
  struct node *predecesor;
  unsigned distance = 0;
  bool operator<(const node& other) const {
    return this->distance < other.distance;
  }
  bool operator>(const node& other) const {
    return this->distance > other.distance;
  }
};

struct graph {
  vector<struct node> V;
};

typedef unordered_map<node*, unordered_map<node*, unsigned>> WeightMap;

void initialize_single_source (graph *G, node *source) {
  for (unsigned i = 0; i < G->V.size(); i++) {
    G->V[i].distance = 99999999;
    G->V[i].predecesor = NULL;
  }
  source->distance = 0;
}

void relax (node *u, node *v,  WeightMap w) {
  unsigned d = (u->distance + w[u][v]);
  if (v->distance > d) {
    v->distance = d;
    v->predecesor = u;
  }
}

void dijkstra (graph *G, WeightMap w, node *source) {
  initialize_single_source(G, source);
  unordered_set<node*> *S = new unordered_set<node*>();
  PriorityQueue<node*> *Q = new PriorityQueue<node*>(G->V.size());

  for (unsigned i = 0; i < G->V.size(); i++) {
    Q->insert(&G->V[i]);
  }

  while (!Q->isEmpty()) {
    node *u = Q->minimum();
    S->insert(u);
    for (unsigned i = 0; i < u->adj.size(); i++) {
      relax(u, &u->adj[i], w);
    }
    Q->extractMin();
  }
}

node* init_graph (graph *G, WeightMap &w, unsigned v_count, float epsilon, unsigned &E_count, bool silent) {
    if (!silent)
      cout << "Initialize Vertices... ";
    
    // For randomization
    random_device rd;   // Used to initialize seed engine
    mt19937 rng(rd());  // Random number engine
    uniform_real_distribution<float> rand_float(0, 1);
    uniform_int_distribution<int> rand_int(0, 9999);

    // The source node
    node *s = new node();
    G->V.push_back(*s);
    
    // Initialize graph with v_count nodes
    for (unsigned i = 1; i < v_count; i++) {
      node n;
      G->V.push_back(n);
    }

    if (!silent)
      cout << "Done" << endl << "Generating random edges... ";

    // Randomly generate edges
    float alpha;
    for (unsigned i = 0; i < v_count - 1; i++) {
      for (unsigned j = i + 1; j < v_count; j++) {
        alpha = rand_float(rng);
        if (alpha > epsilon) {
          // Add to adjacency list
          G->V[i].adj.push_back(G->V[j]);
          G->V[j].adj.push_back(G->V[i]);

          // Create random weight
          unsigned weight = rand_int(rng);
          w[&G->V[j]][&G->V[i]] = weight;
          w[&G->V[i]][&G->V[j]] = weight;
          E_count++;
          if (!silent)
            cout << endl << i << " <-> " << j << " : " << weight;
        }
      }
    }
    
    if (!silent) {
      cout << endl << "Done" << endl;
    }
    return s;
}

int main(int argc, char const *argv[]) {
  float epsilon = 0.4; // For random edges, P((u,v) in E) = 1 - epsilon
  cout << "data = [" << endl;

  for (unsigned v_count = 2; v_count <= 30; v_count++) {
    graph *G = new graph();
    
    // A hash table that maps (node*, node*) -> int
    WeightMap w;
    unsigned E_count = 0;
    node *s = init_graph(G, w, v_count, epsilon, E_count, true);

    clock_t start = clock();
    dijkstra(G, w, s);
    cout << v_count << ' ' << clock() - start << ' ' << E_count * log(v_count) / log(2) << endl;

    delete G;
  }
  cout << "];" << endl;

  return 0;
}
