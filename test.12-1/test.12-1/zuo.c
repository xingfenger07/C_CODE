#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//打印一个数的每一位
//int print(unsigned int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int unsigned n = 0;
//	scanf("%d", &n);
//	int get = print(n);
//	return 0;
//}


//int Num(int n)
//{
//	if (n > 1)
//	{
//		return n *= Num(n - 1);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int Fac = Num(n);
//	printf("%d", Fac);
//	return 0;
//}


//int my_strlen(char* str)
//{
//	if ('\0' == *str)
//		return 0;
//	else
//		return 1 + my_strlen(1 + str);
//}
//int main()
//{
//	char str[100];
//	scanf("%s", str);
//	int  ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}

//字符串逆序（递归实现）
//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列，不是逆序打印。
//要求：不能使用C函数库中的字符串操作函数。


void reverse_string(char* string)
{
	int len = strlen(string);
	char tmp = *string;
	*string = *(string + len - 1);

	*(string + len - 1) = '\0';
	if (strlen(string + 1) >= 2)
		reverse_string(string + 1);

	*(string + len - 1) = tmp;
}

int main()
{
	char string[100];
	scanf("%s", string);
	return 0;
}