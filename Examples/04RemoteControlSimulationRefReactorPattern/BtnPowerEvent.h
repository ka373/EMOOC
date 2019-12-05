#ifndef BTNPOWEREVENT_H__
#define BTNPOWEREVENT_H__

#include "BtnEvent.h"

class_begin(BtnPowerEvent) inherited_from(BtnEvent)
class_end(BtnPowerEvent)

void init_BtnPowerEvent(pointer_to_class(BtnPowerEvent));
BtnPowerEvent *new_BtnPowerEvent();

#endif // !BTNPOWEREVENT_H__