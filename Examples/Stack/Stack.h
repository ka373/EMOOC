#ifndef STACK_H__
#define STACK_H__

#include "emooc.h"
#define MAX_SIZE 25000000

class_begin_with_private(Stack)

	class_func(int, is_empty)(pointer_to_class(Stack));
	class_func(int, is_full)(pointer_to_class(Stack));
	class_func(int, push_int)(pointer_to_class(Stack), int item);
	class_func(int, pop_int)(pointer_to_class(Stack));

class_end_with_private(Stack)

#endif // !STACK_H__