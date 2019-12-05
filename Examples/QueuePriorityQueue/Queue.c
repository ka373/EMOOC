#define Queue_protected //for using protected members
#include "Queue.h"

private_begin(Queue)
	int n;
	int queue[MAX_Q];
	int front;
	int rear;
private_end(Queue)

////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Queue)
int is_empty(pointer_to_class(Queue)) {
	mk_myself_private(Queue);
	if (myself_private.front == -1) {return 1;}
	else {return 0;}
}
////////////////////////////////////////////////////////////////////////////////
class_func_def(int, is_full)(pointer_to_class(Queue)) {
	mk_myself_private(Queue);
	if (myself_private.rear == myself.private_pointer->n - 1) { return 1; }
	else { return 0; }
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Queue)
void insert_data(pointer_to_class(Queue), int val) {
	mk_myself_private(Queue);

	if (is_full(myself_pointer))				puts("Queue Overflow");
	else {
		if (is_empty(myself_pointer))		myself_private.front = 0;
		myself_private.rear++;
		myself_private.queue[myself_private.rear] = val;
	}
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Queue)
void delete_data(pointer_to_class(Queue)) {
	mk_myself_private(Queue);

	if (is_empty(myself_pointer) || myself_private.front > myself_private.rear) {
		puts("Queue Underflow");
		return;
	}
	else {myself_private.front++;}
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Queue)
void display_data(pointer_to_class(Queue)) {
	mk_myself_private(Queue);
	if(is_empty(myself_pointer))	puts("Queue is empty");
	
	else{
		puts("The elements of the queue are: ");
		for(int i = myself_private.front; i <= myself_private.rear; i++)
			printf("%d ", myself_private.queue[i]);
		puts("");
	}
}
////////////////////////////////////////////////////////////////////////////////
	void init_Queue(pointer_to_class(Queue)) {
		malloc_private(Queue);

		myself.private_pointer->n = MAX_Q;
		myself_private.front = -1;
		myself_private.rear = -1;

		myself.insert_data = insert_data;
		myself.delete_data = delete_data;
		myself.display_data = display_data;
	}
////////////////////////////////////////////////////////////////////////////////