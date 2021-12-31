#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>


typedef int ListDataType; //creating the type the list will be

typedef struct Node_t //struct node
{
	ListDataType data; 
	Node* next; 
}Node;

typedef struct List_t //struct list
{
	Node* head; 
}List;

int main()
{
	return 0;
}

List* CreateList() //create empty list ie just head pointing to null and data to be 0
{
	Node* newNode = CreateEmptyNode();
	List list; 
	list.head = newNode; 
	return &list; 
}
Node* CreateHead(ListDataType value, List *list) 
{
	list->head->data = value;
	list->head->next = NULL;
	return list->head; 

}

Node* CreateEmptyNode()
{
	Node newNode = { 0, NULL };
	Node *ptrNewNode = &newNode;
	ptrNewNode->data = 0;
	ptrNewNode->next = NULL;
	return ptrNewNode; 
}

void FreeList(List* list) //free memory of each node in list by looping through list
{
	Node *temp1 = list->head, *temp2;
	while(temp1 != NULL)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2; 
	}
	
}

size_t GetListSize(List* list) //get size by looping through list and counting each iteration
{
	Node* temp1 = list->head;
	size_t n = 0; 
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		n++; 
	}
	return n; 
}

Node* GetListHead(List* list)
{
	return list->head; 
}

Node* GetNextNode(Node* currentNode)
{
	return currentNode->next; 
}

ListDataType GetValue(Node* node)
{
	return node->data; 
}

Node* Insert(Node* after, ListDataType newValue) //insert node after after node given. 
{
	Node* temp1, *newNode = CreateEmptyNode();
	if (after == NULL)
	{
		printf("ERROR\n");
		exit(1); 
	}
	else
	{
		temp1 = after->next;  
		newNode->data = newValue;
		newNode->next = temp1;  
		after->next = newNode; 
		return newNode; 
	}

}

Node* PushFront(List* list, ListDataType newValue)
{
	Node *temp1 = list->head, *newNode = CreateEmptyNode();
	newNode->data = newValue; 
	newNode->next = list->head; 
	list->head = newNode; 
	return newNode; 

}

Node* PushBack(List* list, ListDataType newValue)
{
	Node *temp1 = list->head, *newNode = CreateEmptyNode();
	newNode->data = newValue; 
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = newNode; 
	newNode->next = NULL;
	return newNode; 
}

ListDataType PopFront(List* list)
{
	Node *temp1 = list->head->next; 
	free(list->head);
	list->head = temp1; 
	return temp1->data; 
}

ListDataType PopBack(List* list)
{
	Node* temp1 = list->head, * temp2; 
	size_t n;
	temp2 = temp1->next; 
	if (temp1 == NULL)
	{
		printf("error \n");
		exit(1);
	}
	else if (temp1->next == NULL)
	{
		free(temp1);
		list->head = NULL; 
		return 0; 
	}
	while (temp2->next != NULL)
	{
		temp1 = temp2;
		temp2 = temp2->next; 
	}
	n = temp2->data; 
	free(temp2); 
	temp1->next = NULL; 
	return n; 
}

void DeleteListNode(List* list, Node* target)
{
	Node* temp1 = list->head;
	while (temp1->next != target)
	{
		temp1 = temp1->next; 
	}
	temp1->next = target->next; 
	free(target); 
}

Node* DeleteListValue(List* list, ListDataType value)
{
	Node* temp1 = list->head; 
	while (temp1->data != value)
	{
		temp1 = temp1->next;
	}
	temp1->data = 0; 
	return temp1; 
}

Node* FindInList(List* list, ListDataType value)
{
	Node* temp1 = list->head; 
	while (temp1->data != value)
	{
		temp1 = temp1->next; 
	}
	return temp1; 
}

