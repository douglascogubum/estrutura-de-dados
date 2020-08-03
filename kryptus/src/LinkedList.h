/*
 * LinkedList.h
 *
 *  Created on: 28 de jul de 2020
 *      Author: Douglas Cogubum
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct LinkedList {
	int data;
	struct LinkedList* next;
};


// PROTOTYPES
void put(int data);
int get(int index);
void list();
int first();
int last();
void clear();
int removeList(int index);


#endif /* LINKEDLIST_H_ */
