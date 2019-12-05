#include"PriorityQueue.h"

private_begin(PriorityQueue)
contents priority_queue[MAX_PQ];
int item_count;
private_end(PriorityQueue)

////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(PriorityQueue)
int is_empty(pointer_to_class(PriorityQueue)) {
	mk_myself_private(PriorityQueue);

	if (myself_private.item_count == 0) { return 1; }
	else { return 0; }
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(PriorityQueue)
int is_full(pointer_to_class(PriorityQueue)) {
	mk_myself_private(PriorityQueue);

	if (myself_private.item_count == MAX_PQ) { puts("Priority Queue Overflow"); return 1; }
	else { return 0; }
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(PriorityQueue)
void insert_data(pointer_to_class(PriorityQueue), int val, int pri) {
	mk_myself_private(PriorityQueue);

	int i = 0;
	if (!myself.from_Queue.is_full(myself_pointer)) {
		// if queue is empty, insert_data the pri 
		if (myself.from_Queue.is_empty(myself_pointer)) {
			myself_private.priority_queue[myself_private.item_count].priority = pri;
			myself_private.priority_queue[myself_private.item_count].value = val;
			myself_private.item_count++;
		}
		else {
			// start from the right end of the queue 
			for (i = myself_private.item_count - 1; i >= 0; i--) {
				// if pri is larger, shift existing item to right end 
				if (pri > myself_private.priority_queue[i].priority) {
					myself_private.priority_queue[i + 1] = myself_private.priority_queue[i];
				}
				else { break; }
			}
			// insert_data the pri 
			myself_private.priority_queue[i + 1].priority = pri;
			myself_private.priority_queue[i + 1].value = val;
			myself_private.item_count++;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(PriorityQueue)
void delete_data(pointer_to_class(PriorityQueue)) {
	mk_myself_private(PriorityQueue);

	myself_private.priority_queue[--myself_private.item_count];
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(PriorityQueue)
void display_data(pointer_to_class(PriorityQueue)) {
	mk_myself_private(PriorityQueue);

	if (myself.from_Queue.is_empty(&myself)) { puts("Priority queue is emppty"); }
	else {
		puts("The elements of the priority queue are: ");
		for (int i = myself_private.item_count - 1; i >= 0; i--) {
			printf("value: %d, priority: %d\n", myself_private.priority_queue[i].value, myself_private.priority_queue[i].priority);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
void init_PriorityQueue(pointer_to_class(PriorityQueue)) {
	calloc_private(PriorityQueue);

	init_Queue(&myself.from_Queue);

	myself.from_Queue.delete_data = delete_data;
	myself.from_Queue.display_data = display_data;

	myself.from_Queue.is_empty = is_empty;
	myself.from_Queue.is_full = is_full;

	myself.insert_data = insert_data;
}
////////////////////////////////////////////////////////////////////////////////