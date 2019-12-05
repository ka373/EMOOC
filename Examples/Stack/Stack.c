#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

private_begin(Stack)
	int data[MAX_SIZE];
	int top;
	class_func(void, error)(const char *msg);
private_end(Stack)

////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Stack)
int is_empty(pointer_to_class(Stack)) {
	if (myself.private_pointer->top == 0) return 1;
	else return 0;
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Stack)
int is_full(pointer_to_class(Stack)) {
	if (myself.private_pointer->top == MAX_SIZE) return 1;
	else return 0;
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Stack)
void error(const char *msg) {
	printf("Error: %s", msg);
	printf("Exit the program\n");
	exit(-1);
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Stack)
int push_int(pointer_to_class(Stack), int item) {
	if (is_full(myself_pointer)) error(myself_pointer, "Lack of stack space");
	myself.private_pointer->data[myself.private_pointer->top++] = item;
}
////////////////////////////////////////////////////////////////////////////////
member_function_definition_of_the(Stack)
int pop_int(pointer_to_class(Stack)) {
	if (is_empty(myself_pointer)) error(myself_pointer, "The stack is empty");
	return myself.private_pointer->data[--myself.private_pointer->top];
}
////////////////////////////////////////////////////////////////////////////////
void init_Stack(pointer_to_class(Stack)) {
	malloc_private(Stack)
	myself_private.top = 0;

	myself_private.error = error;
	myself.is_empty = is_empty;
	myself.is_full = is_full;
	myself.pop_int = pop_int;
	myself.push_int = push_int;
}
////////////////////////////////////////////////////////////////////////////////
Stack *new_Stack() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	init_Stack(s);
	return s;
}