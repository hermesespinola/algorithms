#include <iostream>
#include <functional>
#include <string>
#include <stdlib.h>
#include <vector>
#include "linked_list.cpp"

using namespace std;

// Implementation with weighted-union heuristic
class disjoint_set {
    private:
        vector<linked_list*> sets;
        unsigned count, n_sets;
    public:
        disjoint_set() {
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
            
            // auto it = std::find(sets.begin(), sets.end(), y->list);
            // if (it != sets.end()) {
            //     using std::swap;

            //     // swap the one to be removed with the last element
            //     // and remove the item at the end of the container
            //     swap(*it, sets.back());
            //     sets.pop_back();
            // }

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

int main(int argc, char const *argv[]) {
    disjoint_set *ds = new disjoint_set();
    node *n1 = new node(11), *n2 = new node(22), *n3 = new node(33);

    ds->make_set(n1);
    ds->make_set(n2);
    ds->make_set(n3);
    ds->print();
    cout << ds->is_same_set(n1, n2) << endl;
    ds->uni(n1, n2);
    cout << ds->is_same_set(n1, n2) << endl;

    return 0;
}
