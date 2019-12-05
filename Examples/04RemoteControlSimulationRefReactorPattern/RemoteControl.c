#include "RemoteControl.h"

private_begin(RemoteControl)
	BtnEvent *pBtnEvent;
	BtnPowerEvent *pBtnPowerEvent;
	BtnWindEvent *pBtnWindEvent;

	class_func(void, set_btn)(pointer_to_class(RemoteControl), int btn_type);
private_end(RemoteControl)

/////////////////////////////////////////////////////////////////////////////////
class_func_def(void, set_btn)(pointer_to_class(RemoteControl), int btn_type) {
	mk_myself_private(RemoteControl);
	switch (btn_type) {
	case BTN_POWER:			myself_private.pBtnEvent = myself_private.pBtnPowerEvent;			break;
	case BTN_WIND:			myself_private.pBtnEvent = myself_private.pBtnWindEvent;			break;
	default:				puts("Unregistered button");										break;
	}
}
/////////////////////////////////////////////////////////////////////////////////
class_func_def(void, btn_press)(pointer_to_class(RemoteControl), Fan* pFan, int btn_type) {
	mk_myself_private(RemoteControl);
	set_btn(myself_pointer, btn_type);
	myself_private.pBtnEvent->btn_press(myself_private.pBtnEvent, pFan);
}

/////////////////////////////////////////////////////////////////////////////////
void init_RemoteControl(pointer_to_class(RemoteControl)) {
	malloc_private(RemoteControl);

	myself_private.pBtnWindEvent = new_BtnWindEvent();
	myself_private.pBtnPowerEvent = new_BtnPowerEvent();

	myself.btn_press = btn_press;
}