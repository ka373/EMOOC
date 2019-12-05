#include "LightingEquipment.h"

private_begin(LightingEquipment)
	int is_on;
	State *state_pointer;
	StateOn *state_on_pointer;
	StateOff *state_off_pointer;
	class_func(void, set_state)(pointer_to_class(LightingEquipment), int want_on);
private_end(LightingEquipment)

class_func_def(void, set_state)(pointer_to_class(LightingEquipment), int want_on) {
	mk_myself_private(LightingEquipment);

	switch (want_on) {
	case 0:
		myself_private.state_pointer = myself_private.state_off_pointer;
		myself_private.is_on = 0;
		break;

	default:
		myself_private.state_pointer = myself_private.state_on_pointer;
		myself_private.is_on = 1;
		break;
	}
}

class_func_def(void, btn_press)(pointer_to_class(LightingEquipment)) {
	mk_myself_private(LightingEquipment);

	myself_private.state_pointer->btn1_press(myself_private.state_pointer);

	switch (myself_private.is_on) {
	case 0:		myself_private.set_state(myself_pointer, 1);		break;
	default:	myself_private.set_state(myself_pointer, 0);		break;
	}
}
////////////////////////////////////////////////////
void init_LightingEquipment(pointer_to_class(LightingEquipment), int want_on) {
	malloc_private(LightingEquipment);
	
	myself_private.state_on_pointer = new_StateOn();
	myself_private.state_off_pointer = new_StateOff();

	myself_private.set_state = set_state;

	switch (want_on) {
	case 0:		myself_private.set_state(myself_pointer, 0);		break;
	default:	myself_private.set_state(myself_pointer, 1);		break;
	}

	myself.btn1_press = btn_press;
	myself.btn2_press = btn_press;
	myself.btn3_press = btn_press;
}

LightingEquipment* new_LightingEquipment(int want_on) {
	LightingEquipment* temp_LightingEquipment = (LightingEquipment*)malloc(sizeof(LightingEquipment));
	init_LightingEquipment(temp_LightingEquipment, want_on);
	return temp_LightingEquipment;
}