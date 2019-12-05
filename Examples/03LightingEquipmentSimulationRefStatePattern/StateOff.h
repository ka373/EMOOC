#ifndef STATEOFF_H__
#define STATEOFF_H__

#include "State.h"

class_begin_with_private(StateOff) inherited_from(State)
class_end_with_private(StateOff)

void init_StateOff(pointer_to_class(StateOff));
StateOff* new_StateOff();

#endif // !STATEOFF_H__