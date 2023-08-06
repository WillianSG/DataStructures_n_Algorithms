#include <cstdlib>
#include<iostream>

using namespace std;

typedef struct ll_node {
	// Node struct used to store elements in a stack.
	
	int value;
	struct ll_node *next;
} NODE;

NODE *create_node(int val) {
	// Initializes a node structure and returns a pointer to it.
	
	NODE *newnode = (NODE*)malloc(sizeof(NODE));

	newnode->value = val;
	newnode->next = NULL;

	return newnode;
}

void push(NODE **headref, NODE *newnode) {

    newnode->next = *headref;
    *headref = newnode;
}

void pop(NODE **headref) {

	*headref = (*headref)->next;
}

void show_stack(NODE **headref) {
	// Traverses the stack and shows all stores values.

	NODE **list_tracer = headref;

	while (*list_tracer) {

		cout << (*list_tracer)->value << '\n';
		
		list_tracer = &(*list_tracer)->next;
	}
}

int main() {

	NODE *head = (NODE*)malloc(sizeof(NODE));
	head = NULL;

	cout << "\nstacking...\n";

	push(&head, create_node(3));
	push(&head, create_node(2));
	push(&head, create_node(7));

	show_stack(&head);

    cout << "\npop\n";

    pop(&head);
    show_stack(&head);

    cout << "\npop\n";

    pop(&head);
    show_stack(&head);
}