/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 2
 * Date: 30 SEP 2019
 * File: homework2.h
 *
 * */
#ifndef HW2_HEADER_H_
#define HW2_HEADER_H_

#include <stdio.h>
#include <unistd.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include "sys/alt_irq.h"



#define DISP1_INPUT0 0x00040000
#define DISP1_INPUT1 0x00041000
#define DISP1_INPUT2 0x00042000
#define DISP1_INPUT3 0x00043000
#define DISP1_INPUT4 0x00044000
#define DISP1_INPUT5 0x00045000
#define DISP1_INPUT6 0x00046000

#define DISP2_INPUT0 0x00047000
#define DISP2_INPUT1 0x00048000
#define DISP2_INPUT2 0x00049000
#define DISP2_INPUT3 0x0004A000
#define DISP2_INPUT4 0x0004B000
#define DISP2_INPUT5 0x0004C000
#define DISP2_INPUT6 0x0004D000

volatile int edge_capture = 0;
volatile int counter;

void displayNumber(int number);
void init_button();
void button_isr(void* context, alt_u32 id);


#endif /* HW2_HEADER_H_ */
