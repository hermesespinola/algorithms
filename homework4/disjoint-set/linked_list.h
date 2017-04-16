#include <iostream>
#include <functional>
#include <string>
#include <stdlib.h>

using namespace std;

struct node;
struct linked_list;

struct node {
    int key;
    node *previous, *next;
    linked_list *list;

    node(int k) {
        key = k;
        list = NULL;
        previous = next = NULL;
    }

    node(int k, linked_list *l) {
        list = l;
        key = k;
        previous = next = NULL;
    }

    node(int k, node *prev, linked_list *l) {
        list = l;
        key = k;
        previous = prev;
        next = NULL;
    }

    node(int k, node *prev, node *nxt, linked_list *l) {
        list = l;
        key = k;
        previous = prev;
        next = nxt;
    }
};


// Insert only
struct linked_list {
    node *head, *tail;
    int length;

    linked_list() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    linked_list(int first_key) {
        node *n = new node(first_key, this);
        head = n;
        tail = n;
        length = 1;
    }

    linked_list(node *first_node) {
        first_node->previous = first_node->next = NULL;
        first_node->list = this;
        head = first_node;
        tail = first_node;
        length = 1;
    }

    void push_back(int key) {
        node *n = new node(key, tail, this);
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
        }
        tail = n;
        length++;
    }

    void push_back(node *x) {
        x->list = this;
        x->previous = tail;
        if (head == NULL) {
            head = x;
            tail = x;
        } else {
            tail->next = x;
        }
        tail = x;
        length++;
    }

    void push_front(int key) {
        node *n = new node(key, NULL, head, this);
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            head->previous = n;
        }
        head = n;
        length++;
    }

    void push_front(node* x) {
        x->previous = NULL;
        x->next = head;
        x->list = this;
        if (head == NULL) {
            head = x;
            tail = x;
        } else {
            head->previous = x;
        }
        head = x;
        length++;
    }

    void append(linked_list *l) {
        tail->next = l->head;
        l->head->previous = tail;
        
        node *current = l->head;
        while (current != NULL) {
            current->list = this;
            current = current->next;
        }
        tail = l->tail;
        length += l->length;
    }

    void print() {
        cout << "[ ";
        node *current = head;
        
        while (current != NULL) {
            cout << current->key << ' ';
            current = current->next;
        }
        cout << ']' << endl;
    }
};