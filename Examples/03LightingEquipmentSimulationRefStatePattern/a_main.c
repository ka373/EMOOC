#include <stdio.h>
#include <time.h>

#include "StateOn.h"
#include "StateOff.h"
#include "LightingEquipment.h"

#define BTN1_PRESS \
pLightingEquipment->btn1_press(pLightingEquipment);

#define BTN2_PRESS \
pLightingEquipment->btn2_press(pLightingEquipment);

#define BTN3_PRESS \
pLightingEquipment->btn3_press(pLightingEquipment);

int main() {
	LightingEquipment* pLightingEquipment = new_LightingEquipment(0);

	clock_t clock_start_operation, clock_end_operation;
	int elapsed_operation = 0;

	clock_start_operation = clock();
	////////////////////////////////////////////////////
	//perform the following operation 7,000,000 times: 
	//press button 1-> press button 2-> press button 3
	for (int i = 0; i < 7000000; i++){
	BTN1_PRESS	BTN2_PRESS	BTN3_PRESS
	}
	////////////////////////////////////////////////////
	clock_end_operation = clock();
	elapsed_operation = (int)(clock_end_operation - clock_start_operation);

	puts(" [EMOOC: Lighting equipment simulation]");
	printf(" Start       : %dms\n", (int)clock_start_operation);
	printf(" End         : %dms\n", (int)clock_end_operation);
	printf(" Elapsed time: %dms\n", elapsed_operation);
	puts("");
	return 0;
}