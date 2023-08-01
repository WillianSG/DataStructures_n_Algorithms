#include <cstdlib>
#include<iostream>

using namespace std;

typedef struct ll_node {
	// Node struct used to store elements in a linked list.
	
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

void append_node(NODE **headref, NODE *newnode) {
	// Adds a new value to the end of the linked list.

	// Local reference to list's head.
	NODE **list_tracer = headref;

	while (*list_tracer) {						// Pointer to list's node.

		// Updates tracer with address of pointer for next node (pointer-2-pointer).
		list_tracer = &(*list_tracer)->next;	
	}

	newnode->next = *list_tracer; 				// Next of new node set to null.
	*list_tracer = newnode;						// List's tail updated with new node.
}

void prepend_node(NODE **headref, NODE *newnode) {
	// Adds a new value to the begining of the linked list (new head).

	newnode->next = *headref;
	*headref = newnode;
}

void show_list(NODE **headref) {
	// Traverses the linked list and shows all stores values.

	NODE **list_tracer = headref;

	while (*list_tracer) {

		cout << (*list_tracer)->value << '\n';
		
		list_tracer = &(*list_tracer)->next;
	}
}

int main() {

	NODE *head = (NODE*)malloc(sizeof(NODE));
	head = NULL;

	append_node(&head, create_node(15));
	append_node(&head, create_node(1));
	append_node(&head, create_node(20));
	append_node(&head, create_node(9));

	show_list(&head);

	cout << '\n';

	prepend_node(&head, create_node(0));
	prepend_node(&head, create_node(7));

	show_list(&head);

}