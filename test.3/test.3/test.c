#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//二分查找
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", & k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left <= right)
//	{
//		/*int mid = (left + right) / 2;*/
//		int mid = left + (right - left);
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是:%d\n", mid);
//			break;
//		}
//		if (left > right)
//		{
//			printf("找不到");
//		}
//	}
//	return 0;
//}

//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "wellcom to China ! ! !";
//	char arr2[] = "######################";
//	int left = 0;
//	int right = strlen(arr1) - 1;//或者int right = sizeof(arr) / sizeof(arr[0]) - 2;
//
//	while(left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//
//	return 0;
//}

#include<string.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		char password[20] = { 0 };
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "asdfgh") == 0)
//		{
//			printf("登入成功\n");
//			break;
//		}
//		else
//		{
//			printf("请重新输入密码\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("退出程序");
//	}
//	
//	return 0;
//}





#include <stdlib.h>
#include <time.h>

//void menu()
//{
//	printf("#########################\n");
//	printf("####### 1.play   ########\n");
//	printf("####### 2.exit   ########\n");
//	printf("#########################\n");
//}
//
//void game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	/*printf("%d\n", ret);*/
//	while(1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//			printf("猜小了\n");
//		else if (guess > ret)
//			printf("猜大了\n");
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//
//			
//	}
//}
//
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//
//		}
//	} while (input);
//	return 0;
//}




//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("请注意，你的电脑将在120秒关机，请输入：不要，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "不要") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//		
//	return 0;
//}

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//
//	while (1)
//	{
//		printf("请注意，你的电脑将在120秒关机，请输入：不要，就取消关机\n");
//		scanf("%s", input);
//		if (strcmp(input, "不要") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	/*char arr1[20] = { 0 };
//	char arr2[] = "hello world";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);*/
//	char arr[] = "hello world";
//	memset(arr + 6, 'x', 3);
//	printf("%s", arr);
//
//	return 0;
//}


//int get_max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_max(a, b);
//	printf("%d", m);
//
//	return 0;
//}


//当实参传给形参时，形参是实参的一份临时拷贝
//对形参的修改不影响实参
//形式参数
// void Swap(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
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