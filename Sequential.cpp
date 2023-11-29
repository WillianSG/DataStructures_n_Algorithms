#include <cstdlib>
#include<iostream>

using namespace std;

class Sequential {

    protected:

    struct node {
        int value;
        struct node *next;
    };

    node *create_node(int val) {
        node *new_node = new node;

        new_node->value = val;
        new_node->next = nullptr;

        return new_node;
    }

    node *head;

    public:

    Sequential() : head(nullptr) {}

    ~Sequential() {
        node* node_tracer = head;

        while (node_tracer) {
            node* temp = node_tracer;
            node_tracer = node_tracer->next;
            delete temp;
        }
    }

    void show() {
        if (!head) { 
            cout << "Empty data structure." << endl;
        } else {
            cout << "Content:" << endl;

            node **node_tracer = &head;

            while (*node_tracer) {
                cout << (*node_tracer)->value << endl;
                node_tracer = &(*node_tracer)->next;
            }

            cout << endl;
        }
    }

    virtual void push(int val) =0;
    virtual int pop() =0;
};

class Queue : public Sequential {
    
    public:

    void push(int val) override {
        node **node_tracer = &head;
        node *new_node = create_node(val);

        while (*node_tracer) {
            node_tracer = &(*node_tracer)->next;	
        }

        new_node->next = *node_tracer;
        *node_tracer = new_node;
    };

    int pop() override {

        if (!head) { 
            cout << "Empty queue." << endl;
            return -1;
        } else {
            int value = head->value;

            node *temp = head;
            head = head->next;

            delete temp;
            return value;
        }
    }

};

int main() {

    Queue q;

    q.show();

    q.push(5);
    q.push(10);
    q.push(15);
    q.show();

    q.pop();
    q.show();

    q.push(20);
    q.show();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}