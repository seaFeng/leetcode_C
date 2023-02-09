#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int val;
	struct listNode* next;
};

typedef struct listNode listNodeT;
typedef struct listNode* listNodePtr;

listNodePtr resultListHead = NULL;
listNodePtr resultCurrentListNode = NULL;

void addList(int value) {
	if (resultListHead == NULL) {
		resultListHead = malloc(sizeof(listNodeT));
		if (resultListHead != NULL) {
			resultListHead->val = value;
			resultListHead->next = NULL;
		}
		resultCurrentListNode = resultListHead;
	} else {
		resultCurrentListNode->next = malloc(sizeof(listNodeT));
		if (resultCurrentListNode->next != NULL)
		{
			resultCurrentListNode = resultCurrentListNode->next;
			resultCurrentListNode->next = NULL;
			resultCurrentListNode->val = value;
		}
	}
}

listNodePtr addTwoNums(listNodePtr list1, listNodePtr list2) {


	while (list1 != NULL || list2 != NULL)
	{
		int jinWeiFlag = 1;
		int tmpResult = 0;
		if (list1 != NULL && list2 != NULL)
		{
			if (jinWeiFlag)
			{
				tmpResult = list1->val + list2->val + 1;
				jinWeiFlag = 0;
			}
			else {
				tmpResult = list1->val + list2->val;
			}

			
			if (tmpResult > 9)
			{
				addList(tmpResult - 10);
				jinWeiFlag = 1;
				
			} else {
				addList(tmpResult);
			}
		}

		list1++;
		list2++;
	}

	return resultListHead;
}

void main() {

}
