#ifndef FAN_H__
#define FAN_H__

#include <stdio.h>
#include "emooc.h"

#define WIND_MAX 3
enum IsOn { FAN_OFF, FAN_ON };

class_begin(Fan)
	int is_on;
	int wind_volume;
	class_func(void, print_fan_state)(pointer_to_class(Fan));
class_end(Fan)

void init_Fan(pointer_to_class(Fan));

#endif // !FAN_H__
