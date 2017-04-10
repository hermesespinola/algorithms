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
  // Initialize graph
  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // random number engine
  uniform_real_distribution<float> uni(0, 1); // unbiased

  unsigned v_count = 10, epsilon = 0.5;
  Graph *G = (Graph *) malloc(sizeof(Graph));
  WeightMap *w = new WeightMap();

  for (unsigned i = 0; i < v_count; i++) {
    Node *n = (Node *) malloc(sizeof(Node));
    G->V[i].adj.push_back(*n); // FIXME: wtf
  }

  for (unsigned i = 0; i < v_count - 1; i++)
    for (unsigned j = 1; j < v_count; j++) {
      float alpha = uni(rng);
      if (alpha > epsilon) {
        G->V[i].adj.push_back(G->V[j]);
        G->V[j].adj.push_back(G->V[i]);
      }
    }
}

