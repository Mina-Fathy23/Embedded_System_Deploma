/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#include "fifo.h"

int main(void)
{
	FIFO_buff_t FIFO_UART;
	element_type i, temp;
	if(FIFO_init(&FIFO_UART, buffer, width) == FIFO_no_error)
		printf("FIFO init ----- Done\n");

	for(i = 0; i < 7; i++)
	{
		printf("FIFO Enqueue (%x) \n", i);
		if(FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\t fifo enqueue ---- Done \n");
		else
			printf("\t fifo enqueue ---- failed \n");
	}

	FIFO_print(&FIFO_UART);
	if(FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\t fifo dequeue %x ---- Done \n", temp);
	if(FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\t fifo dequeue %x ---- Done \n", temp);
	FIFO_print(&FIFO_UART);
	return 1;

}
