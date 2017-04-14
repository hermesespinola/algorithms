#include <iostream>
#include <functional>
#include <string>

using namespace std;

class disjoint_set {
    private:
        int *p, *rank, *size, n_sets, p_c;
    public:
        void make_set(unsigned n) {
            p = new int[n];
            rank = new int[n];
            size = new int[n];
            for (unsigned i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
                rank[i] = 0;
            }
            n_sets = n;
            p_c = n;
        }

        disjoint_set(unsigned n) {
            make_set(n);
        }

        int find(unsigned x) {
            if (x >= p_c)
                throw std::length_error("Index out of bounds");
            unsigned i = x;
            while (i != p[i])
                i = p[i];
            p[x] = i;
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
            
            if (rank[i_parent] <= rank[j_parent]) {
                p[j_parent] = i_parent;
                size[i_parent] += size[j_parent];

                if (rank[i_parent] == rank[j_parent]) {
                    rank[i_parent] += 1;
                }
            } else {
                p[i_parent] = j_parent;
                size[j_parent] += size[i_parent];
                if (rank[i_parent] == rank[j_parent]) {
                    rank[j_parent] += 1;
                }
            }
            n_sets--;
        }

        int num_sets() {
            return n_sets;
        }

        int size_of_set(int i) {
            return size[find(i)];
        }

        void print() {
            cout << "[ ";
            for (unsigned i = 0; i < p_c; i++) {
                cout << p[i] << ' ';
            }
            cout << "]" << endl;
        }
};

int main(int argc, char const *argv[]) {
    disjoint_set *ds = new disjoint_set(10);
    ds->print();
    ds->uni(2, 6);
    ds->uni(1, 2);
    ds->uni(5, 9);
    ds->uni(5, 2);
    ds->print();
    return 0;
}
