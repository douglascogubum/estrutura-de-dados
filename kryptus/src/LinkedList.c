/*
 * LinkedList.c
 *
 *  Created on: 28 de jul de 2020
 *      Author: Douglas Cogubum
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

struct LinkedList *head = NULL;

void put(int data)
{
	struct LinkedList *currentList = (struct LinkedList *) malloc(sizeof(struct LinkedList));
	struct LinkedList *current;

	currentList->data = data;

	if(head == NULL) {
		head = currentList;
		head->next = NULL;
		return;
	}

	current = head;

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = currentList;
	currentList->next = NULL;

}

int get(int index)
{
	struct LinkedList* currentList = head;

	if(head == NULL)
	{
		return 0;
	}

	for (int i = 0; i < (index - 1); i++)
	{
		if(currentList->next == NULL)
		{
			return 0;
		}
		else
		{
			currentList = currentList->next;
		}
	}

	return currentList->data;
}

void list()
{
	struct LinkedList *current = head;

	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
}

int first()
{
	return head->data;
}

int last()
{
	struct LinkedList *current, *last;
	int data;

	if(head->next == NULL)
	{
		return head->data;
	}

	current = head;

	while(current->next != NULL)
	{
		last = current;
		current = current->next;
	}

	last->next = NULL;
	data = current->data;
	free(current);

	return data;
}

void clear()
{
	struct LinkedList *current;

	current = head;

	while(current->next != NULL)
	{
		current = current->next;
		free(current);
	}

	free(head);
	head = NULL;
}

int removeList(int index)
{
	struct LinkedList* currentList = head;
	struct LinkedList* previousList = NULL;

	if(head == NULL)
	{
		return 0;
	}

	for(int i = 0; i < (index - 1); i++)
	{
		if(currentList->next == NULL)
		{
			return 0;
		}
		else
		{
			previousList = currentList;
			currentList = currentList->next;
		}
	}

	if(currentList == head)
	{
		head = head->next;
	}
	else
	{
		previousList->next = currentList->next;
	}

	return currentList->data;
}
