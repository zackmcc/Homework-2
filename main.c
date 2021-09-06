/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 2
 * Date: 30 SEP 2019
 * File: main.c
 *
 * */

#include <stdio.h>
#include <unistd.h>
#include "homework2.h"

volatile int counter;

int main(){
	int tst;
	counter = 0; 	//Initialize counter to 0
	displayNumber(counter); 	//Initialize display to 00
	init_button();	//Resister button ISR

	// Enable Interrupt
	tst = alt_ic_irq_enable(PIO_14_IRQ_INTERRUPT_CONTROLLER_ID,
							PIO_14_IRQ);

	//Check if Interrupt was enabled successfully
	if (tst<0) 
		printf("\nFailed to enable interrupt, enable returned %d", tst);
	else 
		printf("\n Interrupt Enabled.");

	// Enter infinite loop
	while(1)
	{
		//Check if ISR was triggered
		if (edge_capture !=0)
		{
			counter++;	//Iterate counter

			// If counter is greater than 12 reset to 0
			if (counter > 12)
			{
				counter = 0;
			}

			// Display new counter value
			displayNumber(counter);

			//Reset edge capture value
			edge_capture = 0;
		}
	}
	return 0;
}


void displayNumber(int num)
{
	int* display1[] = {DISP1_INPUT0,DISP1_INPUT1,
					DISP1_INPUT2,DISP1_INPUT3,
	                DISP1_INPUT4,DISP1_INPUT5,
					DISP1_INPUT6};
	int* display2[] = {DISP2_INPUT0,DISP2_INPUT1,
					DISP2_INPUT2,DISP2_INPUT3,
	                DISP2_INPUT4,DISP2_INPUT5,
					DISP2_INPUT6};

	for(int i = 0; i < sizeof(display1)/sizeof(display1[0]); i++)
	{
		*display1[i] = 0x01;
		*display2[i] = 0x01;
	}

	switch(num)
	{
	case 0:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[5] = 0x00;
		return;
	case 1:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[1] = 0x00;
		*display1[2] = 0x00;
		return;
	case 2:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[6] = 0x00;
		return;
	case 3:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[6] = 0x00;
		return;
	case 4:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[5] = 0x00;
		*display1[6] = 0x00;
		return;
	case 5:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[5] = 0x00;
		*display1[6] = 0x00;
		return;
	case 6:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[5] = 0x00;
		*display1[6] = 0x00;
		return;
	case 7:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		return;
	case 8:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[5] = 0x00;
		*display1[6] = 0x00;
		return;
	case 9:
		*display2[0] = 0x00;
		*display2[1] = 0x00;
		*display2[2] = 0x00;
		*display2[3] = 0x00;
		*display2[4] = 0x00;
		*display2[5] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[5] = 0x00;
		*display1[6] = 0x00;
		return;
	case 10:
		*display2[1] = 0x00;
		*display2[2] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[2] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[5] = 0x00;

		return;
	case 11:
		*display2[1] = 0x00;
		*display2[2] = 0x00;

		*display1[1] = 0x00;
		*display1[2] = 0x00;
		return;
	case 12:
		*display2[1] = 0x00;
		*display2[2] = 0x00;

		*display1[0] = 0x00;
		*display1[1] = 0x00;
		*display1[3] = 0x00;
		*display1[4] = 0x00;
		*display1[6] = 0x00;
		return;
	}
}

void button_isr(void* context, alt_u32 id){
	//Set context to edge_capture_ptr value
	volatile int* edge_capture_ptr = (volatile int*) context;
	//Read edge capture register of PIO_14 (Button)
	*edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PIO_14_BASE);

	//Write 1 to edge capture register
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_14_BASE, 0x1);
	return;
}

void init_button()
{
	//Type cast edge_capture variable so it can 
	//be passed to register function
	void* edge_capture_ptr = (void*) &edge_capture;

	//Write 1 to IRQ Mask
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_14_BASE, 0x1);
	//Write 0 to edge capture of PIO_14(Button)
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_14_BASE, 0x0);

	//Register Interrupt
	alt_ic_isr_register(PIO_14_IRQ_INTERRUPT_CONTROLLER_ID,
						PIO_14_IRQ,
						(void*)button_isr,
						edge_capture_ptr,
						0x0);
}
