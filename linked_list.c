/*
 * linked_list.c
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */
#include "linked_list.h"


void createList(nodePtr *list)
{
	(*list) = NULL;
	printf("List Created Successfully.");
}

void insertToList(nodePtr *listHead, unsigned char position, int data)
{
	nodePtr ptr = (nodePtr) malloc(sizeof(Node));
	ptr->data = data;
	if ((*listHead) == NULL)/* empty list. */
	{
		/**
		 * 1 - create new node.
		 * 2 - put data to node.
		 * 3 - insert node at head position.
		 */
		(*listHead) = ptr;
		(*listHead)->ptr = NULL;
	}else
	{
		/**
		 * insert node at specific position.
		 */
		nodePtr before  = (nodePtr)malloc(sizeof(Node));
		nodePtr before_free = before;
		before->ptr      = (*listHead);
		nodePtr current = (*listHead);
		int i = 0;
		while(i <= position)
		{
			if (i == position)
			{
				before->ptr  = ptr;
				ptr->ptr     = current;/* new node. */
				break;
			}
			i++;
			current = current->ptr;
			before  = before->ptr;
		}
		free(before_free);
	}
}

void deleteFromList(nodePtr *listHead, unsigned char position, int* data)
{
	if ((*listHead) == NULL)/* empty list. */
	{
		printf("List not contains any nodes.");
	}else
	{
		/**
		 * insert node at specific position.
		 */
		nodePtr before  = (nodePtr)malloc(sizeof(Node));
		nodePtr before_free = before;
		before->ptr      = (*listHead);
		nodePtr current = (*listHead);
		int i = 0;
		while(i <= position)
		{
			if (i == position)
			{
				before->ptr  = current->ptr;
				break;
			}
			i++;
			current = current->ptr;
			before  = before->ptr;
		}
		*data = current->data;
		free(before_free);
		free(current);
	}
}

unsigned char searchIntoList(nodePtr *listHead, int data)
{
	nodePtr current = (*listHead);
	unsigned char is_found = 0;
	if ((*listHead) == NULL)
	{
		printf("List is empty.");
	}else
	{
		while(current != NULL)
		{
			if (current->data == data)
			{
				is_found = 1;
				break;
			}
		}
	}
	return is_found;
}

void sortList(nodePtr *listHead)
{

	if ((*listHead) == NULL)
	{
		printf("Empty List.");
	}else if ((*listHead)->ptr == NULL)
	{
		printf("This List Contains only one node.");
	}else
	{
		/**
		* loop for all elements in list.
		* if element1->val > element2->val swap by
			 * element1-> element2->next.
			 * element2->next = element1.
		*/
		size_t i = 0;
		size_t list_counter = count_list_items(listHead);
		nodePtr current = (*listHead);
		nodePtr temp = (nodePtr) malloc(sizeof(Node));
		temp->ptr  = current;
		temp->data = -1;

		nodePtr prev = (nodePtr) malloc(sizeof(Node));
		prev->ptr  = temp;
		prev->data = -1;
		nodePtr copy_prev = prev;
		nodePtr copy_temp = temp;
		while(i <= list_counter)
		{
			//if (i == 3) { printf("current %d temp %d \n ", current->data, temp->data);}
			while(current != NULL)
			{
				if (temp->data > current->data)
				{
					temp->ptr       = current->ptr;
					current->ptr    = temp;
					prev->ptr       = current;
					if (temp == (*listHead))
					{
						/* updating head. */
						(*listHead) = current;
					}
					nodePtr temp1 = temp;
					temp    = current;
					current = temp1;
				}
				current = current->ptr;
				temp    = temp->ptr;
				prev    = prev->ptr;
			}
			current = (*listHead);
			temp    = copy_temp;
			prev    = copy_prev;
			i++;
		}
	}
}

void reverseList(nodePtr *listHead)
{
	nodePtr current = (*listHead);
	nodePtr tail    = NULL;
	/**
	 * 1 - search tail.
	 */
	if ((*listHead) == NULL)
	{
		printf("List is Empty.");
	}else
	{
		while(current->ptr != NULL)
		{
			current = current->ptr;
		}
		tail = current;
		if (tail == (*listHead))
		{
			printf("List Consists of one element.");
		}else
		{
			unsigned int counter = count_list_items(listHead);
			unsigned int i = 0, start_ptr = 0 ,j = counter - 1, pos = 0, count = 0;
			current = (*listHead);
			nodePtr temp = (*listHead);
			while( i < (counter/2) )
			{
				//go to position at which should be reversed data.
				pos = j - i;
				while(count <= pos)
				{
					if (count == i)
					{

						start_ptr = 1;
					}
					if (count == pos)
					{
						int data = current->data;
						current->data = temp->data;
						temp->data = data;
					}
					current = current->ptr;/* last. */
					count++;

					if (start_ptr == 0)
					{
						temp = temp->ptr;
					}

				}
				start_ptr = 0;
				i++;
				current = (*listHead);
				temp    = (*listHead);
				count   = 0;
			}
		}
	}


}

void printList(nodePtr *listHead)
{
	printf("\n");
	nodePtr current = (*listHead);
	while(current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->ptr;
	}
	printf("null \n");
}


int count_list_items(nodePtr *listHead)
{
	nodePtr current = (*listHead);
	int i = 0;
	while(current != NULL)
	{
		i++;
		current = current->ptr;
	}
	return i;
}


