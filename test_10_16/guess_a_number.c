//猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1
//scanf函数在C99标准中被认为是不安全的，会出现警告信息，所以要加上这行代码来关闭警告信息
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(void)
{
	int count = 0;//记录猜的次数，最多只能猜5次，否则游戏失败
	int guess = 0;
	printf("游戏开始, 范围是1~100，请在5次内猜中\n");

	//生成一个1~100的随机数
	int r = rand() % 100 + 1;//rand()函数生成的随机数范围是0~RAND_MAX，RAND_MAX是一个常量，表示rand()函数能返回的最大值
	//rand() % 100的结果是0~99，再加1就是1~100的随机数
	int start = (int)time(NULL);//记录游戏开始的时间

	//开始猜数字
	while (count < 5)
	{
		printf("请输入你猜的数字：>");
		scanf("%d", &guess);
		count++;//记录猜的次数加1
		printf("当前已花费时间：%d秒\n", (int)time(NULL) - start);
		//计算当前已花费的时间，time(NULL)返回的是从1970年1月1日0时0分0秒到现在的秒数，所以要减去游戏开始的时间

		if (guess > r)
		{
			printf("猜大了, 还有%d次机会\n", 5 - count);
		}
		else if (guess < r)
		{
			printf("猜小了, 还有%d次机会\n", 5 - count);
		}
		else
		{
			printf("恭喜你，猜对了！你用了%d次猜中了数字\n", count);
			return;
		}
	}
	if (count == 5)
	{
		printf("很遗憾，5次机会用完了，游戏失败\n");
		printf("正确的数字是：%d\n", r);
	}
}

void menu(void)
{
	printf("*************************\n");
	printf("***** 1.开始游戏 ********\n");
	printf("***** 0.退出游戏 ********\n");
	printf("*************************\n");
}

int main(void)
{
	int input = 0;
	srand((unsigned int)time(NULL)); //设置随机数种子
	//如果在循环内设置种子，当用户输入间隔过短时，每次循环都会生成相同的随机数，所以要在循环外设置种子

	//菜单至少打印一次，所以用do while循环
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{

		case 1:
		{
			game();//开始游戏
			break;
		} 

		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("无效输入，请输入0或者1\n");
			break;
		}

		}
	} while (input);

	return 0;
}