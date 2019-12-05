#include "BtnPowerEvent.h"

member_function_definition_of_the(BtnPowerEvent)
void btn_press(pointer_to_class(BtnPowerEvent), Fan *pFan) {
	switch (pFan->is_on) {
	case FAN_OFF:		pFan->is_on = FAN_ON;	pFan->wind_volume = 1;	break;
	case FAN_ON:	pFan->is_on = FAN_OFF;		pFan->wind_volume = 0;	break;
	default:															break;
	}
}

//////////////////////////////////////////////////////////////////////
void init_BtnPowerEvent(pointer_to_class(BtnPowerEvent)) {
	myself.from_BtnEvent.btn_press = btn_press;
}
BtnPowerEvent* new_BtnPowerEvent() {
	BtnPowerEvent* temp_BtnPowerEvent = (BtnPowerEvent*)malloc(sizeof(BtnPowerEvent));
	init_BtnPowerEvent(temp_BtnPowerEvent);
	return temp_BtnPowerEvent;
}