#ifndef REMOTECONTROL_H__
#define REMOTECONTROL_H__

#include "emooc.h"
#include "Fan.h"
#include "BtnWindEvent.h"
#include "BtnPowerEvent.h"

class_begin_with_private(RemoteControl)
	class_func(void, btn_press)(pointer_to_class(RemoteControl), Fan* pFan, int btn_type);
class_end_with_private(RemoteControl)

void init_RemoteControl(pointer_to_class(RemoteControl));

#endif // !REMOTECONTROL_H__