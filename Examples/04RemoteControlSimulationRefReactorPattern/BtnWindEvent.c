#include "BtnWindEvent.h"

member_function_definition_of_the(BtnWindEvent)
void btn_press(pointer_to_class(BtnWindEvent), Fan *pFan) {

	switch (pFan->wind_volume) {
	case 0:									break;
	case WIND_MAX: pFan->wind_volume = 1;	break;
	default: pFan->wind_volume++;			break;
	}

}
/////////////////////////////////////////////////////////////////////////////////
void init_BtnWindEvent(pointer_to_class(BtnWindEvent)) {
	myself.from_BtnEvent.btn_press = btn_press;
}
BtnWindEvent* new_BtnWindEvent() {
	BtnWindEvent* temp_BtnWindEvent = (BtnWindEvent*)malloc(sizeof(BtnWindEvent));
	init_BtnWindEvent(temp_BtnWindEvent);
	return temp_BtnWindEvent;
}