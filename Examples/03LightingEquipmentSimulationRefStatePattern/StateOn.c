#include <stdio.h>
#include "StateOn.h"

private_begin(StateOn)
	int btn_led[3];
private_end(StateOn)

member_function_definition_of_the(StateOn)
void btn_press(pointer_to_class(StateOn)) {
	mk_myself_private(StateOn);
	for (int i = 0; i < 3; i++) {myself_private.btn_led[i] = 1;}
}
////////////////////////////////////////////////////
void init_StateOn(pointer_to_class(StateOn)) {
	calloc_private(StateOn);
	myself.from_State.btn1_press = btn_press;
	myself.from_State.btn2_press = btn_press;
	myself.from_State.btn3_press = btn_press;
}
StateOn* new_StateOn() {
	StateOn* temp_StateOn = (StateOn*)malloc(sizeof(StateOn));
	init_StateOn(temp_StateOn);
	return temp_StateOn;
}