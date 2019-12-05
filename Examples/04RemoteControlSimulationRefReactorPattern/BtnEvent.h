#ifndef BTNEVENT_H__
#define BTNEVENT_H__

#include "emooc.h"
#include "Fan.h"

#define BTN_POWER 0
#define BTN_WIND 1

outline_class_begin(BtnEvent)
	outline_class_func(void, btn_press)(pointer_to_class(BtnEvent), Fan *pFan);
outline_class_end(BtnEvent)

#endif // !BTNEVENT_H__