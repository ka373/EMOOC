#ifndef QUEUE_H__
#define QUEUE_H__

#include<stdio.h>
#include"emooc.h"

#define MAX_Q 100

class_begin_with_private(Queue)

	//member function
	class_func(void, insert_data)(pointer_to_class(Queue), int val);
	class_func(void, delete_data)(pointer_to_class(Queue));
	class_func(void, display_data)(pointer_to_class(Queue));

	//protected
	#ifdef Queue_protected
		class_func(int, is_empty)(pointer_to_class(Queue));
		class_func(int, is_full)(pointer_to_class(Queue));
	#endif //Queue_protected

class_end_with_private(Queue)

void init_Queue(pointer_to_class(Queue));
#endif // !QUEUE_H__