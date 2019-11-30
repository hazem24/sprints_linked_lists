/*
 * queue.c
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */

#include "queue.h"

static unsigned int start_position = 0;
static unsigned int end_position = 0;

void createQueue(nodePtr* info)
{
	createList(info);
}
void enqueue(nodePtr* info, int data)
{
	insertToList(info, start_position, data);
	printf("\n%d is added to queue.\n", data);
	start_position++;
}
void dequeue(nodePtr* info, int* data)
{
	deleteFromList(info , 0, data);
	printf("\n%d is added to dequeue.\n", *data);
	//start_position--;
}

unsigned char queue_is_empty()
{
	if (end_position == 0) return 1;
	return 0;
}

