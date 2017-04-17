#include <iostream>
#include <functional>
#include <string>
#include <stdlib.h>
#include <vector>
#include "linked_list.h"

using namespace std;

// Implementation with weighted-union heuristic
class linked_disjoint_set {
    private:
        vector<linked_list*> sets;
        unsigned count, n_sets;
    public:
        linked_disjoint_set() {
            sets = *new vector<linked_list*>();
            n_sets = 0;
            count = 0;
        }

        void make_set(node *x) {
            sets.push_back(new linked_list(x));
            count += 1;
            n_sets += 1;
        }

        node* find(node *x) {
            return x->list->head;
        }

        bool is_same_set(node *x, node *y) {
            return find(x) == find(y);
        }

        void uni(node *x, node *y) {
            node *x_parent = find(x);
            node *y_parent = find(y);

            if (x_parent == y_parent)
                return;

            if (x->list->length < y->list->length) {
                x->list->append(y->list);
            } else {
                y->list->append(x->list);
            }

            n_sets--;
        }

        int num_sets() {
            return n_sets;
        }

        void print() {
            cout << "{" << endl;
            for (unsigned i = 0; i < n_sets; i++) {
                sets[i]->print();
            }
            cout << "}" << endl;
        }
};
