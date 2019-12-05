#include "Fan.h"

def_class_func(void, print_fan_state)(pointer_to_class(Fan)) {
	printf("is_on: %d\n", myself.is_on);
	printf("wind_volume: %d\n", myself.wind_volume);
}

void init_Fan(pointer_to_class(Fan)) {
	myself.is_on = 0;
	myself.wind_volume = 0;
	myself.print_fan_state = print_fan_state;
}