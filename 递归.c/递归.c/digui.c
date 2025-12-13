#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//递归：大事化小
//void print(int unsigned n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int unsigned i = 0;
//	scanf("%d", &i);
//	print(i);
//	return 0;
//}

//不创建临时变量，计算字符串大小

//创建临时变量写法
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

//不创建临时变量写法
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//n的阶乘
//int fac(int n)
//{
//	//递归
//	/*if (n <= 1)
//	{
//		return 1;
//	}
//	else
//		return n * fac(n - 1);
//	*/
//	//循环
//	/*int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;*/
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//	return 0;
//}



//斐波那契数列
//递归
//int fie(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return (fie(n - 1) + fie(n - 2));
//
//}//计算结果正确，因栈溢出，效率低

//迭代
//int fie(int n)
//{
//	int i = 1;
//	int j = 1;
//	int k = 0;
//	while (n > 2)
//	{
//		k = i + j;
//		i = j;
//		j = k;
//		n--;
//	}
//	return k;
//}
////效率快但结果不对
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fie(n);
//	printf("%d\n",ret);
//	return 0;
//}