#include <iostream>
#include "priorityqueue.cpp"
#include <vector>
#include <random>
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
typedef struct node Node;

struct graph {
  vector<struct node> V;
};
typedef struct graph Graph;

typedef unordered_map<Node*, unordered_map<Node*, unsigned>> WeightMap;

void initialize_single_source(Graph *G, Node *source) {
  for (unsigned i = 0; i < G->V.size(); i++) {
    G->V[i].distance = 99999999;
    G->V[i].predecesor = NULL;
  }
  source->distance = 0;
}

void relax(Node *u, Node *v,  WeightMap w) {
  unsigned d = (u->distance + w[u][v]);
  if (v->distance > d) {
    v->distance = d;
    v->predecesor = u;
  }
}

void dijkstra (Graph *G, WeightMap w, Node *source) {
  initialize_single_source(G, source);
  unordered_set<Node*> *S = new unordered_set<Node*>();
  PriorityQueue<Node*> *Q = new PriorityQueue<Node*>(G->V.size());

  for (unsigned i = 0; i < G->V.size(); i++) {
    Q->insert(&G->V[i]);
  }

  while (!Q->isEmpty()) {
    Node *u = Q->minimum();
    S->insert(u);
    for (unsigned i = 0; i < u->adj.size(); i++) {
      relax(u, &u->adj[i], w);
    }
    Q->extractMin());
  }
}

int main(int argc, char const *argv[]) {
  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // Random number engine
  uniform_real_distribution<float> rand_float(0, 1);
  uniform_int_distribution<int> rand_int(0, 9999);

  unsigned v_count = 30;
  float alpha, epsilon = 0.8; // For random edges, P((u,v) in E) = 1 - epsilon
  Graph *G = (Graph *) malloc(sizeof(Graph));

  // A hash tap maps (Node*, Node*) -> int
  WeightMap w;

  cout << "Initialize Vertices... ";
  // The source node
  Node *s = new Node();
  G->V.push_back(*s);
  
  // Initialize graph with v_count nodes
  for (unsigned i = 1; i < v_count; i++) {
    Node *n = new Node();
    G->V.push_back(*n);
  }
  
  cout << "Done" << endl << "Generating random edges... ";

  // Randomly generate edges
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
        cout << endl << i << " <-> " << j << " : " << weight;
      }
    }
  }
  
  cout << endl << "Done" << endl << "Executing Dijkstra... " << endl;

  dijkstra(G, w, s);
  cout << "Done" << endl;

  return 0;
}
