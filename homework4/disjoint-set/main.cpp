#include <iostream>
#include "linked_disjoint_set.h"
#include "disjoint_set.h"
#include <random>

int main() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> rand_int(0, 9999);

    cout << "dsTime = [" << endl;
    for (unsigned n = 2; n <= 1000; n++) {
        disjoint_set *ds = new disjoint_set(n);
        linked_disjoint_set();
    }
    
    cout << "];" << endl;
}
