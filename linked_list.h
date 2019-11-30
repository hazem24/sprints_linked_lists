/*
 * linked_list.h
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include "stdlib.h"


/**
 * AGILE_REQ5:
Implement the following APIs for a simple linear Linked List that stores integer values.
Use the following prototypes:

	char createList(ST_list *list);
	void insertToList(ST_node *listHead, unsigned char position, int data);
	void deleteFromList(ST_node *listHead, unsigned char position, int* data);
	ST_node* searchIntoList(ST_node *listHead, int data);
	void sortList(ST_node *listHead);	//Bonus
	void reverseList(ST_node *listHead);	//Bonus
 *
 */
typedef struct node
{
	int data;
	struct node* ptr;
}Node;

typedef Node* nodePtr;


void createList(nodePtr *list);

void insertToList(nodePtr *listHead, unsigned char position, int data);
void deleteFromList(nodePtr *listHead, unsigned char position, int* data);
unsigned char searchIntoList(nodePtr *listHead, int data);
void sortList(nodePtr *listHead);
void reverseList(nodePtr *listHead);
void printList(nodePtr *listHead);
int count_list_items(nodePtr *listHead);



#endif /* LINKED_LIST_H_ */
