#ifndef ZHYLINKLIST_H
#define ZHYLINKLIST_H

#include<stdlib.h>

struct listNode {
	int val;
	struct listNode* next;
};

typedef struct listNode listNodeT;
typedef struct listNode* listNodePtr;

struct ZHYLinkList
{
	listNodePtr listHeadPtr;
	listNodePtr listCurrentNodePtr;
};

void addList(int value, struct ZHYLinkList* list) {
	if (list == NULL) {
		return;
	}

	if (list->listHeadPtr != NULL) 
	{
		listNodePtr newNode = (listNodePtr) malloc(sizeof(listNodeT));
		newNode->val = value;
		list->listHeadPtr = list->listCurrentNodePtr = newNode;
		list->listHeadPtr->next = NULL;
		list->listCurrentNodePtr->next = NULL;
	}
	else 
	{
		list->listCurrentNodePtr->next = (listNodePtr) malloc(sizeof(listNodeT));
		list->listCurrentNodePtr->next->val = value;
		list->listCurrentNodePtr = list->listCurrentNodePtr->next;
		list->listCurrentNodePtr->next = NULL;
	}
}

#endif /* UTHASH_H */