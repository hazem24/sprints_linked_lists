/*
 * queue.h
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "linked_list.h"
#include <stdio.h>



void createQueue(nodePtr* info);
void enqueue(nodePtr* info, int data);
void dequeue(nodePtr* info, int* data);


#endif /* QUEUE_H_ */
