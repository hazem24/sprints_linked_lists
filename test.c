/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "string_balanced_checker.h"
#include "linked_list.h"
#include "queue.h"

nodePtr linked_list_head;
nodePtr queue_head;
int main()
{
	int data;
	createList(&linked_list_head);

	insertToList(&linked_list_head, 0,20);

	insertToList(&linked_list_head, 1,4);

	insertToList(&linked_list_head, 2,30);

	insertToList(&linked_list_head, 3,60);

	insertToList(&linked_list_head, 4,10);

	insertToList(&linked_list_head, 5,30);

	insertToList(&linked_list_head, 3,3);

	printList(&linked_list_head);
	//sortList(&linked_list_head);
	//deleteFromList(&linked_list_head, 5, &data);
	reverseList(&linked_list_head);
	printList(&linked_list_head);
	//{}[]()({}((((((({}))))))))))))){}
	printf("%d ", searchIntoList(&linked_list_head, 30));



	char dota = 0;
	//queue_head
	createQueue(&queue_head);
	enqueue(&queue_head, 10);
	enqueue(&queue_head, 20);
    enqueue(&queue_head, 70);

    dequeue(&queue_head, &dota);

    printf("is balanced %d",evaluate("9-3"));


}
