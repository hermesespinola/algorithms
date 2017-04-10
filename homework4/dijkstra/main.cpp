#include <iostream>
#include "priorityqueue.cpp"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <stdio.h> // FIXME: replace to include NULL

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
  for (unsigned i = 0; i < G->V.size(); i++) { // FIXME: vector.lenght (?)
    G->V[i].distance = 99999999;      // TODO: find a MAXINT constant
    G->V[i].predecesor = NULL;    // FIXME: find include
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

void dijkstra (Graph *G, WeightMap w, Node *s) {
  initialize_single_source(G, s);
  unordered_set<Node*> *S = new unordered_set<Node*>();
  PriorityQueue<Node*> *Q = new PriorityQueue<Node*>(G->V.size());
  while (!Q->isEmpty()) {
    Node *u = Q->extractMin();
    S->insert(u);
    for (unsigned i = 0; i < u->adj.size(); i++) {
      relax(u, &u->adj[i], w);
    }
  }
}

int main(int argc, char const *argv[]) {
  return 0;
}
