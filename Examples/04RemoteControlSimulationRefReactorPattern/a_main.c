#include <stdio.h>
#include <time.h>

#include "BtnWindEvent.h"
#include "BtnPowerEvent.h"
#include "RemoteControl.h"

#define NUM_REMOTE_CONTROL 25000
#define NUM_TEST_PER_ONE_REMOTE 100

int main() {
	Fan fan1 = init_instance init_Fan(&fan1);
	Fan fan2 = init_instance init_Fan(&fan2);

	RemoteControl RemoteControl[NUM_REMOTE_CONTROL];
	for (int i = 0; i < NUM_REMOTE_CONTROL; i++) {init_RemoteControl(&RemoteControl[i]);}

	clock_t clock_start_operation, clock_end_operation;
	int elapsed_operation = 0;

	////////////////////////////////////////////////////////////////////////////////
	clock_start_operation = clock();

	//Test 25,000 remote controls on two fans
	//Repeat the following operation 100 times on each remote control:
	//power button -> wind change button 3 times -> power button
	for (int i = 0; i < NUM_REMOTE_CONTROL; i++) {

		for (int j = 0; j < NUM_TEST_PER_ONE_REMOTE; j++) {
			
			RemoteControl[i].btn_press(&RemoteControl[i], &fan1, BTN_POWER);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan1, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan1, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan1, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan1, BTN_POWER);

			RemoteControl[i].btn_press(&RemoteControl[i], &fan2, BTN_POWER);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan2, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan2, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan2, BTN_WIND);
			RemoteControl[i].btn_press(&RemoteControl[i], &fan2, BTN_POWER);
		}
	}

	clock_end_operation = clock();
	////////////////////////////////////////////////////////////////////////////////
	elapsed_operation = (int)(clock_end_operation - clock_start_operation);

	puts(" [EMOOC: Fan remote control test]");
	printf(" Start       : %dms\n", (int)clock_start_operation);
	printf(" End         : %dms\n", (int)clock_end_operation);
	printf(" Elapsed time: %dms\n", elapsed_operation);
	puts("");
	
	return 0;
}