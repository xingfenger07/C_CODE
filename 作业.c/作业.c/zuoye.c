#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//// 递归辅助函数：交换左右指针所指字符，直到相遇或交错
//static void reverse_string_helper(char* left, char* right)
//{
//    if (left >= right)
//        return;
//    char tmp = *left;
//    *left = *right;
//    *right = tmp;
//    reverse_string_helper(left + 1, right - 1);
//}
//
//// 对外接口：找到字符串结尾（不使用库函数），调用辅助递归
//void reverse_string(char* s)
//{
//    if (s == NULL) return;
//    char* end = s;
//    while (*end != '\0')  ++end;    // 手动寻找终止字符
//    if (end == s) return;          // 空字符串
//    reverse_string_helper(s, end - 1);
//}
//
//int main()
//{
//    char arr[] = "abcdef";
//    reverse_string(arr);
//    printf("%s\n", arr); // 输出: fedcba
//    return 0;
//}



//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//void reverse_string(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str+1) >= 2)
//		reverse_string(str + 1);
//	*(str + len - 1) = tmp;
//}
//
//int main()
//{
//	char str[] = "abcdefg";
//	reverse_string(str);
//	printf("%s\n", str); // 输出: gfedcba)
//	return 0;
//}

//void reverse_string(char* str,int left,int right)
//{
//	char tmp = *(str + left);
//	*(str + left) = *(str + right);
//	*(str + right) = tmp;
//	if(left < right)
//		reverse_string(str, left + 1, right - 1);
//}
//
//int main()
//{
//	char str[] = "abcdefg";
//	int left = 0;
//	int right = (my_strlen(str) - 1);
//	reverse_string(str,left,right);
//	printf("%s\n", str); // 输出: gfedcba)
//	return 0;
//}

//int Digitsum(unsigned int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return n % 10 + Digitsum(n / 10);
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	int sum = Digitsum(n);
//	printf("%d\n", sum);
//	return 0;
//}

double Pow(double n, double k)
{
	if (k > 0)
	{
		return n * Pow(n, k - 1);
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return 1 / Pow(n, -k);
	}
}

int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double ret = Pow(n, k);
	printf("%1f\n", ret);
	return 0;
}