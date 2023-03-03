#include<stdlib.h>
#include<stdio.h>

int checkCharExist(char value, char* array, int length) {
	for (size_t i = 0; i < length; i++)
	{
		if (array[i] == value)
		{
			return 1;
		}
	}

	return 0;
}

int lengthOfLongestSubstring(char* s) {

	char* result = malloc(20 * sizeof(char));
	char* temp = result;
	int arraySize = 20;
	int useSize = 0;
	int maxLength = 0;

	char* j;
	char* i;

	for (i = s; *i != '\0'; i++)
	{
		int currentLength = 0;
		for (j = i; *j != '\0'; j++) {
			
			// À©³äÄÚ´æ
			if (useSize == arraySize)
			{
				result = realloc(result, arraySize * 2 * sizeof(char));
				temp = result + arraySize;
				arraySize *= 2;
			}

			if (useSize == 0 || !checkCharExist(*j, result, useSize)) {
				//printf("%d == %c \n", useSize, *j);
				*temp = *j;
				//printf("%d == %c \n", useSize, *(result--));
				temp++;
				useSize++;
				currentLength++;
			} else {
				maxLength = currentLength > maxLength ? currentLength : maxLength;
				useSize = 0;
				currentLength = 0;
				temp = result;
				break;
			}
			
		}

		if (*j == '\0')
		{
			maxLength = currentLength > maxLength ? currentLength : maxLength;
			useSize = 0;
			currentLength = 0;
			temp = result;
			break;
		}
	}

	return maxLength;
}




void main31() {
	printf("leet code 3 staring \n");
	char* s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int maxLength = lengthOfLongestSubstring(s);
	printf("max length == %d \n", maxLength);
}