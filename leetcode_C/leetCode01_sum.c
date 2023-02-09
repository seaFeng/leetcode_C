#include<stdio.h>
#include "uthash.h"


// hash �� ���ڴ滻ʱ��
struct myHashTable {
	int key;
	int val;
	UT_hash_handle hh;
};

typedef struct myHashTable hashtableT;
typedef struct myHashTable* hashtablePtr;

// hash ��ı�ͷ
hashtablePtr hashTableHead;

/*
*  ��hash���в��Ҷ�Ӧ��key�Ƿ����
*/
hashtablePtr find(int key) {
	struct myHashTable* result;
	// ע�������и����壬ʹ�õ���key�ĵ�ַ��������Ϊɶ����
	HASH_FIND_INT(hashTableHead, &key, result);
	return result;
}

/*
*  ����Ӧ��key value ��ӵ� hash����
*/
void add(int key, int value) {
	// ����key �Ƿ��Ѿ����ڣ����������valueֵ���������ⴴ��һ���ڵ㣬���Ҳ��뵽hash����
	hashtablePtr it = find(key);
	if (it == NULL) {
		hashtablePtr tmp = malloc(sizeof(hashtableT));
		tmp->key = key;
		tmp->val = value;
		HASH_ADD_INT(hashTableHead, key, tmp);
	} else {
		it->val = value;
	}
}

int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
	hashTableHead = NULL;
	int i;
	for (i = 0; i < numsSize; i++)
	{
		hashtablePtr it = find(target - nums[i]);
		if (it != NULL) {
			int* result = malloc(sizeof(int) * 2);
			if (result != NULL) {
				result[0] = i;
				result[1] = it->val;
				*returnSize = 2;
				return result;
			}
		}

		add(nums[i], i);
	}

	*returnSize = 0;
	return NULL;
}
	
	


//�����ƽ�
int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;

	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if ((nums[i] + nums[j]) == target) {
				int* result = malloc(sizeof(int) * 2);
				if (result != NULL)
				{
					result[0] = i;
					result[1] = j;

					*returnSize = 2;
					return result;
				}
			}
		}
	}

	*returnSize = 0;
	return NULL;
}

void main1() {
	int array[] = { 2,7,11,15 };
	int target = 9;
	int returnSize;
	int* result = twoSum2(array, 4, 9, &returnSize);

	if (returnSize == 2)
	{
		printf("result[0] = %d \n result[1] = %d", result[0], result[1]);
		free(result);
		return;
	}
	printf("");
}