#include <stdio.h>
#include <time.h>
#include "Stack.h"

int main() {
	int data = 0;
	int i;
	Stack *stack = new_Stack();

	clock_t clock_start_stack, clock_end_stack;
	int elapsed_stack = 0;

	///////////////////////////////////////////////////////////////////////
	clock_start_stack = clock();

	for (i = 0; i < MAX_SIZE; i++) { stack->push_int(stack, i % 10); }
	while (!stack->is_empty(stack)) { data = stack->pop_int(stack); }

	clock_end_stack = clock();
	///////////////////////////////////////////////////////////////////////
	elapsed_stack = (int)(clock_end_stack - clock_start_stack);
	
	puts(" [EMOOC: Stack]");
	printf(" Start       : %dms\n", (int)clock_start_stack);
	printf(" End         : %dms\n", (int)clock_end_stack);
	printf(" Elapsed time: %dms\n", elapsed_stack);
	puts("");

	return 0;
}