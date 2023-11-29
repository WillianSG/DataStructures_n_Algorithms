#include<cstdlib>
#include<iostream>

using namespace std;

template <class T>
class Sequential {

    protected:

    struct node {
        T value;
        struct node *next;
    };

    node *create_node(T val) {
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
            throw std::runtime_error("Empty data structure.");
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

    virtual void push(T val) =0;
    virtual T pop() =0;
};

template <class T>
class Queue : public Sequential<T> {
    
    public:

    void push(T val) override {
        typename Sequential<T>::node **node_tracer = &this->head;

        // @TODO: Error thrown if "this->" is not used here. Find out why.
        typename Sequential<T>::node *new_node = this->create_node(val);

        while (*node_tracer) {
            node_tracer = &(*node_tracer)->next;	
        }

        new_node->next = *node_tracer;
        *node_tracer = new_node;
    };

    T pop() override {

        if (!this->head) { 
            throw std::runtime_error("Empty queue.");
        } else {
            T value = this->head->value;

            typename Sequential<T>::node *temp = this->head;
            this->head = this->head->next;

            delete temp;
            return value;
        }
    }

};

int main() {

    // Queue<char> q;

    // // q.show();

    // q.push('a');
    // q.push('b');
    // q.push('c');
    // q.show();

    // q.pop();
    // q.show();

    // q.push('d');
    // q.show();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    Queue<int> q;

    // q.show();

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