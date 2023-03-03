#include<stdlib.h>
#include<stdio.h>

int lengthOfLongestSubstring_2(char* s) {
    // 设置最大字符的数量的数组。
    int temp[256] = { 0 };
    int i, start = 0, ans = 0, count = 0;
    for (i = 0; s[i]; i++) {
        // 根据char类型的int 类型，来将数据，放到对应的为
        if (temp[s[i]] == 0) {
            temp[s[i]] = 1;
            count++;
            if (count > ans)ans = count;
        }
        else {
            temp[s[start]] = 0;
            start++;
            count--;
            i--;
        }
    }
    return ans;
}




void main() {
	printf("leet code 3 staring \n");
	char* s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int maxLength = lengthOfLongestSubstring(s);
	printf("max length == %d \n", maxLength);
}