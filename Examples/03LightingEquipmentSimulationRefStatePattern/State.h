#ifndef STATE_H__
#define STATE_H__

#include "emooc.h"

outline_class_begin(State)
	outline_class_func(void, btn1_press)(pointer_to_class(State));
	outline_class_func(void, btn2_press)(pointer_to_class(State));
	outline_class_func(void, btn3_press)(pointer_to_class(State));
outline_class_end(State)

#endif // !STATE_H__