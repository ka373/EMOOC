#ifndef PQUEUE_H__
#define PQUEUE_H__

#include"emooc.h"

#define Queue_protected
#include"Queue.h"

#define MAX_PQ 120000

typedef struct contents {
	int value;
	int priority;
} contents;

class_begin_with_private(PriorityQueue) inherited_from(Queue)
	class_func(void, insert_data)(pointer_to_class(PriorityQueue), int val, int pri);
class_end_with_private(PriorityQueue)

void init_PQ(pointer_to_class(PriorityQueue));

#endif // !PQUEUE_H__