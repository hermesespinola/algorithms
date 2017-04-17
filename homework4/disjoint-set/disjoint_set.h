#include <iostream>
#include <functional>
#include <string>

using namespace std;

class disjoint_set {
    private:
        vector<unsigned> *p, *rank, *size;
        unsigned n_sets, p_c;
    public:
        disjoint_set(unsigned n) {
            p = new vector<unsigned>(n, 0);
            rank = new vector<unsigned>(n, 0);
            size = new vector<unsigned>(n, 1);
            for (unsigned i = 1; i < n; i++) {
                p->at(i) = i;
            }
            n_sets = n;
            p_c = n;
        }

        void make_set() {
            p->push_back(p_c);
            rank->push_back(0);
            size->push_back(0);
            p_c++;
            n_sets++;
        }

        int find(unsigned x) {
            if (x >= p_c)
                throw std::length_error("Index out of bounds");
            unsigned i = x;
            while (i != p->at(i))
                i = p->at(i);
            p->at(x) = i;
            return i;
        }

        bool is_same_set(int i, int j) {
            return find(i) == find(j);
        }

        void uni(int i, int j) {
            int i_parent = find(i);
            int j_parent = find(j);

            if (i_parent == j_parent)
                return;
            
            if (rank->at(i_parent) <= rank->at(j_parent)) {
                p->at(j_parent) = i_parent;
                size->at(i_parent) += size->at(j_parent);

                if (rank->at(i_parent) == rank->at(j_parent)) {
                    rank->at(i_parent) += 1;
                }
            } else {
                p->at(i_parent) = j_parent;
                size->at(j_parent) += size->at(i_parent);
                if (rank->at(i_parent) == rank->at(j_parent)) {
                    rank->at(j_parent) += 1;
                }
            }
            n_sets--;
        }

        int num_sets() {
            return n_sets;
        }

        int size_of_set(int i) {
            return size->at(find(i));
        }

        void print() {
            cout << "[ ";
            for (unsigned i = 0; i < p_c; i++) {
                cout << p->at(i) << ' ';
            }
            cout << "]" << endl;
        }
};
