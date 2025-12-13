#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	printf("hehe\n");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (int i = 1; i <= 20; i++)
//	{
//		printf("%d\n", i);
//	}
//	return 0;
// 
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			/*break;*/
//			continue;
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//n的阶乘
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("%d ", ret);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		/*sum = sum + ret;*/
//		sum += ret;
//	}
//
//	
//	printf("%d ", sum);
//	
//	return 0;
//}



//int max(int x, int y)
//{
//    return x > y ? x : y;
//}

//int main(void)
//{
//    /* p 是函数指针 */
//    int (*p)(int, int) = &max; // &可以省略,函数指针变量P指向函数变量max
//    int a, b, c, d;
//
//    printf("请输入三个数字:");
//    scanf("%d %d %d", &a, &b, &c);
//
//    /* 与直接调用函数等价，d = max(max(a, b), c) */
//    d = p(p(a, b), c);
//
//    printf("最大的数字是: %d\n", d);
//
//    return 0;
//}


//#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
//#include <time.h>
//
//// 游戏区域大小
//#define WIDTH 60
//#define HEIGHT 20
//
//// 方向常量
//#define UP 1
//#define DOWN 2
//#define LEFT 3
//#define RIGHT 4
//
//// 控制台光标位置设置
//void setCursorPosition(int x, int y) {
//    COORD coord = { x, y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//// 隐藏控制台光标
//void hideCursor() {
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 100;
//    cursorInfo.bVisible = FALSE;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}
//
//// 蛇的结构
//typedef struct {
//    int x;
//    int y;
//} Point;
//
//Point snake[WIDTH * HEIGHT]; // 蛇身体数组
//Point food;                 // 食物位置
//int length = 3;             // 初始蛇长
//int direction = RIGHT;      // 初始方向
//int score = 0;              // 得分
//int gameOver = 0;           // 游戏结束标志
//
//// 初始化游戏
//void initGame() {
//    // 初始化蛇的位置（居中）
//    for (int i = 0; i < length; i++) {
//        snake[i].x = WIDTH / 2 - i;
//        snake[i].y = HEIGHT / 2;
//    }
//
//    // 生成第一个食物
//    srand(time(0));
//    food.x = rand() % (WIDTH - 2) + 1;
//    food.y = rand() % (HEIGHT - 2) + 1;
//
//    // 重置游戏状态
//    direction = RIGHT;
//    score = 0;
//    gameOver = 0;
//}
//
//// 绘制游戏界面
//void draw() {
//    system("cls"); // 清屏
//
//    // 绘制上边界
//    for (int i = 0; i < WIDTH + 2; i++)
//        printf("#");
//    printf("\n");
//
//    // 绘制游戏区域
//    for (int y = 0; y < HEIGHT; y++) {
//        for (int x = 0; x < WIDTH; x++) {
//            // 绘制左边界
//            if (x == 0) printf("#");
//
//            // 绘制蛇头
//            if (x == snake[0].x && y == snake[0].y)
//                printf("O");
//            // 绘制蛇身
//            else if (x == food.x && y == food.y)
//                printf("F"); // 食物
//            else {
//                int isBody = 0;
//                for (int k = 1; k < length; k++) {
//                    if (x == snake[k].x && y == snake[k].y) {
//                        printf("o");
//                        isBody = 1;
//                        break;
//                    }
//                }
//                if (!isBody) printf(" ");
//            }
//
//            // 绘制右边界
//            if (x == WIDTH - 1) printf("#");
//        }
//        printf("\n");
//    }
//
//    // 绘制下边界
//    for (int i = 0; i < WIDTH + 2; i++)
//        printf("#");
//    printf("\n");
//
//    // 显示分数
//    printf("Score: %d\n", score);
//    printf("Controls: WASD or Arrow Keys. Press X to quit.\n");
//}
//
//// 处理输入
//void input() {
//    if (_kbhit()) {
//        switch (_getch()) {
//        case 'w': case 'W': case 72: // 上箭头
//            if (direction != DOWN) direction = UP;
//            break;
//        case 's': case 'S': case 80: // 下箭头
//            if (direction != UP) direction = DOWN;
//            break;
//        case 'a': case 'A': case 75: // 左箭头
//            if (direction != RIGHT) direction = LEFT;
//            break;
//        case 'd': case 'D': case 77: // 右箭头
//            if (direction != LEFT) direction = RIGHT;
//            break;
//        case 'x': case 'X':
//            gameOver = 1;
//            break;
//        }
//    }
//}
//
//// 更新游戏状态
//void update() {
//    // 保存蛇尾位置（用于食物检测）
//    Point prevTail = snake[length - 1];
//
//    // 移动蛇身体（从尾部向前更新）
//    for (int i = length - 1; i > 0; i--) {
//        snake[i] = snake[i - 1];
//    }
//
//    // 根据方向移动蛇头
//    switch (direction) {
//    case UP:
//        snake[0].y--;
//        break;
//    case DOWN:
//        snake[0].y++;
//        break;
//    case LEFT:
//        snake[0].x--;
//        break;
//    case RIGHT:
//        snake[0].x++;
//        break;
//    }
//
//    // 检测是否吃到食物
//    if (snake[0].x == food.x && snake[0].y == food.y) {
//        length++; // 增加蛇的长度
//        score += 10;
//
//        // 将蛇尾添加到新位置
//        snake[length - 1] = prevTail;
//
//        // 生成新食物
//        int valid;
//        do {
//            valid = 1;
//            food.x = rand() % (WIDTH - 2) + 1;
//            food.y = rand() % (HEIGHT - 2) + 1;
//
//            // 确保食物不会出现在蛇身上
//            for (int i = 0; i < length; i++) {
//                if (food.x == snake[i].x && food.y == snake[i].y) {
//                    valid = 0;
//                    break;
//                }
//            }
//        } while (!valid);
//    }
//
//    // 检测撞墙
//    if (snake[0].x < 0 || snake[0].x >= WIDTH ||
//        snake[0].y < 0 || snake[0].y >= HEIGHT) {
//        gameOver = 1;
//    }
//
//    // 检测撞到自己
//    for (int i = 1; i < length; i++) {
//        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
//            gameOver = 1;
//            break;
//        }
//    }
//}
//
//int main() {
//    hideCursor(); // 隐藏光标
//
//    initGame();
//
//    while (!gameOver) {
//        draw();
//        input();
//        update();
//        Sleep(100); // 控制游戏速度
//    }
//
//    system("cls");
//    printf("\n\n\tGame Over!\n");
//    printf("\tYour Score: %d\n\n", score);
//    printf("\tPress any key to exit...");
//    _getch(); // 等待按键
//
//    return 0;
//}


//int main()
//{
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	int n = 0;
//
//	for (n = 1; n <= 3; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum += ret;
//	}
//
//	
//	printf("%d ", sum);
//	
//	return 0;
//}







int main() {
    char operator;
    double num1, num2, result;

    // 获取用户输入
    printf("请输入运算符 (+, -, *, /): ");
    scanf("%c", &operator);

    printf("请输入两个数字，用空格隔开: ");
    scanf("%lf %lf", &num1, &num2);

    // 根据运算符进行计算
    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            printf("错误：除数不能为零！\n");
            return 1;  // 非正常退出
        }
        break;
    default:
        printf("错误：无效的运算符！\n");
        return 1;  // 非正常退出
    }

    // 输出结果
    printf("结果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

    return 0;  // 正常退出
}