#ifndef LIGHTINGEQUIPMENT_H__
#define LIGHTINGEQUIPMENT_H__

#include "emooc.h"
#include "State.h"
#include "StateOn.h"
#include "StateOff.h"

class_begin_with_private(LightingEquipment)
	class_func(void, btn1_press)(pointer_to_class(LightingEquipment));
	class_func(void, btn2_press)(pointer_to_class(LightingEquipment));
	class_func(void, btn3_press)(pointer_to_class(LightingEquipment));
class_end_with_private(LightingEquipment)

void init_LightingEquipment(pointer_to_class(LightingEquipment), int want_on);
LightingEquipment* new_LightingEquipment(int want_on);

#endif // !LIGHTINGEQUIPMENT_H__