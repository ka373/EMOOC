#include <stdio.h>
#include "StateOff.h"

private_begin(StateOff)
	int btn_led[3];
private_end(StateOff)

member_function_definition_of_the(StateOff)
void btn_press(pointer_to_class(StateOff)) {
	mk_myself_private(StateOff);
	for (int i = 0; i < 3; i++) {myself_private.btn_led[i] = 0;}
}
////////////////////////////////////////////////////
void init_StateOff(pointer_to_class(StateOff)) {
	malloc_private(StateOff);
	for (int i = 0; i < 3; i++) { myself_private.btn_led[i] = 1; }

	myself.from_State.btn1_press = btn_press;
	myself.from_State.btn2_press = btn_press;
	myself.from_State.btn3_press = btn_press;
}
StateOff* new_StateOff() {
	StateOff* temp_StateOff = (StateOff*)malloc(sizeof(StateOff));
	init_StateOff(temp_StateOff);
	return temp_StateOff;
}