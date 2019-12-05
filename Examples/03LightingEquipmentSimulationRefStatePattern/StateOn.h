#ifndef STATEON_H__
#define STATEON_H__

#include "State.h"

class_begin_with_private(StateOn) inherited_from(State)
class_end_with_private(StateOn)

void init_StateOn(pointer_to_class(StateOn));
StateOn* new_StateOn();

#endif // !STATEON_H__