#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int val;
	struct listNode* next;
};

// 使用typedef
typedef struct listNode listNodeT;
typedef struct listNode* listNodePtr;

listNodePtr addTwoNumbers(listNodePtr list1, listNodePtr list2) {

	listNodePtr head = NULL, tail = NULL;
	int jinWei = 0;

	while (list1 != NULL || list2 != NULL)
	{
		// 这里需要改进，学习了
		int tempValue1 = list1 ? list1->val : 0;
		int tempValue2 = list2 ? list2->val : 0;
		/*if (list1 != NULL)
		{
			tempValue1 = list1->val;
		}

		if (list2 != NULL)
		{
			tempValue2 = list2->val;
		}*/

		// 这里需要改进，学习了。
		int sum = tempValue1 + tempValue2 + jinWei;
		//if (jinWei)
		//{
		//	sum = tempValue1 + tempValue2 + 1;
		//	jinWei = 0;
		//}
		//else {
		//	sum = tempValue1 + tempValue2;
		//}

		if (head == NULL)
		{
			head = tail = malloc(sizeof(listNodeT));
			if (head && tail)
			{
				head->val = sum % 10;
				head->next = NULL;
				tail->next = NULL;
			}
		}
		else {
			tail->next = malloc(sizeof(listNodeT));
			if (tail->next)
			{
				tail = tail->next;
				tail->val = sum % 10;
				tail->next = NULL;
			}

		}

		// 值得学习的代码
		jinWei = sum / 10;

		if (list1)
		{
			list1 = list1->next;
		}

		if (list2)
		{
			list2 = list2->next;
		}

	}

	if (jinWei)
	{
		tail->next = malloc(sizeof(listNodeT));
		if (tail->next) {
			tail = tail->next;
			tail->val = 1;
			tail->next = NULL;
		}

	}

	return head;
}

void main2() {

}
