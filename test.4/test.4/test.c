#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//当实参传给形参时，形参是实参的一份临时拷贝
//对形参的修改不影响实参
//形式参数

//void Swap(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//
//
////实参
//int main()
//{
//	int a = 0;                
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a=%d b=%d\n", a, b);
//	Swap(&a,&b);
//	printf("交换后：a=%d b=%d\n", a, b);
//
//	return 0;
// }    
 

//int chosse(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i +=2 )
//	{
//		if (chosse(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//			
//	}
//	printf("\ncount = %d\n",count);
//	
//	return 0;
//}



//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}

//二分查找

int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]< k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
			return mid;
		
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[ 0 ]);
	int k = 0;
	printf("请输入10以内想搜数字下标：");
	scanf("%d", &k);
	int ret = binary_search(arr, k, sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
		printf("找到了，下标是%d\n",ret);
	return 0;
}



//void Add(int* p)
//{
//	(*p)++;
//}
//
//
//int main()
//{
//	int num = 0;
//	while (num < 10)
//	{
//		Add(&num);
//		printf("%d\n", num);
//	}
//	return 0;
//}


//int main()
//{
//	printf("%d",printf("%d",printf("%d",43)));
//	return 0;
//}
//


int main()
{

	return 0;
}