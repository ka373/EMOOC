#ifndef BTNWINDEVENT_H__
#define BTNWINDEVENT_H__

#include "BtnEvent.h"

class_begin(BtnWindEvent) inherited_from(BtnEvent)
class_end(BtnWindEvent)

void init_BtnWindEvent(pointer_to_class(BtnWindEvent));
BtnWindEvent *new_BtnWindEvent();

#endif // !BTNWINDEVENT_H__