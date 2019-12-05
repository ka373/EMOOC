#include<stdio.h>
#include"emooc.h"

#define Queue_protected //for protected
#include"Queue.h"

#include "PriorityQueue.h"
#include <time.h>

#define VALUE i%10
#define PRIORITY i%10

int main() {
	PriorityQueue priority_queue = init_instance init_PriorityQueue(&priority_queue);
	clock_t start_pqueue, end_pqueue;
	int elapsed_pqueue = 0;
	
	start_pqueue = clock();
	///////////////////////////////////////////////////////////////////////////
	//Inserts 120,000 elements into the Priority Queue
	//and then deletes 120,000 elements
	for (int i = 0; i < MAX_PQ; i++) {priority_queue.insert_data(&priority_queue, VALUE, PRIORITY);}
	for (int i = 0; i < MAX_PQ; i++) {priority_queue.from_Queue.delete_data(&priority_queue);	   }
	///////////////////////////////////////////////////////////////////////////
	end_pqueue = clock();
	elapsed_pqueue = (double)(end_pqueue - start_pqueue);

	puts(" [EMOOC: Priority Queue]");
	printf(" Start       : %dms\n", (int)start_pqueue);
	printf(" End         : %dms\n", (int)end_pqueue);
	printf(" Elapsed time: %dms\n", elapsed_pqueue);
	puts("");
	return 0;
}