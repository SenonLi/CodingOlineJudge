#pragma once

#ifndef __Sen_LinkedListTop10__
#define __Sen_LinkedListTop10__

#include <stdlib.h>
#include <stdio.h>

struct node	{
	int data;
	struct node* next;
};

class Sen_LinkedListTop10
{
public:
	Sen_LinkedListTop10();
	virtual ~Sen_LinkedListTop10();

	void showLinkedListSorting();

private:
	struct node* newNode(int newData);
	void printLinkedList(struct node* nodeHead);
	void sortedInsert(struct node** ptrNodeHead, struct node* newNode);
	void finalizeLinkedList(struct node* nodeHead);
};



#endif