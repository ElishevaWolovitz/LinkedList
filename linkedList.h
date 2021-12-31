#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>


typedef int ListDataType;

typedef struct Node_t Node;

typedef struct List_t List;

List* CreateList();

Node* CreateHead(ListDataType value, List* list); 

Node* CreateEmptyNode(); 

void FreeList(List* list);

size_t GetListSize(List* list);

Node* GetListHead(List* list);

Node* GetNextNode(Node* currentNode);

ListDataType GetValue(Node* node);

Node* Insert(Node* after, ListDataType newValue);

Node* PushFront(List* list, ListDataType newValue);

Node* PushBack(List* list, ListDataType newValue);

ListDataType PopFront(List* list);

ListDataType PopBack(List* list);

void DeleteListNode(List* list, Node* target);

Node* DeleteListValue(List* list, ListDataType value);

Node* FindInList(List* list, ListDataType value);




#endif // !LINKEDLIST_H
