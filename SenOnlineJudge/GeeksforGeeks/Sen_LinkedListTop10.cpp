#include "Sen_LinkedListTop10.h"


Sen_LinkedListTop10::Sen_LinkedListTop10()
{
}


Sen_LinkedListTop10::~Sen_LinkedListTop10()
{
}

struct node* Sen_LinkedListTop10::newNode(int newData)	{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = NULL;
	return newNode;
}

void Sen_LinkedListTop10::printLinkedList(struct node* nodeHead)	{
	struct node* temp = nodeHead;
	while (temp != NULL)	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void Sen_LinkedListTop10::sortedInsert(struct node** ptrNodeHead, struct node* newNode)	{
	struct node* currentNode;
	if (*ptrNodeHead == NULL || (*ptrNodeHead)->data > newNode->data)	{
		newNode->next = *ptrNodeHead;
		*ptrNodeHead = newNode;
	}
	else
	{
		// Locate the node before the point of insertion
		currentNode = *ptrNodeHead;
		while (currentNode->next != NULL && currentNode->next->data < newNode->data)	{
			currentNode = currentNode->next;
		}
		newNode->next = currentNode->next;
		currentNode->next = newNode;
	}
}

void Sen_LinkedListTop10::finalizeLinkedList(struct node* nodeHead)	{
	struct node* currentNode = nodeHead;
	while (nodeHead != NULL)	{
		nodeHead = nodeHead->next;
		free(currentNode);
		currentNode = nodeHead;
	}
}

void Sen_LinkedListTop10::showLinkedListSorting()	{
	struct node* nodeHead = NULL;
	sortedInsert(&nodeHead, newNode(5));
	sortedInsert(&nodeHead, newNode(3));
	sortedInsert(&nodeHead, newNode(1));
	sortedInsert(&nodeHead, newNode(7));
	sortedInsert(&nodeHead, newNode(8));
	printf("\n Created Linked List: \n");
	printLinkedList(nodeHead);
	finalizeLinkedList(nodeHead);
}