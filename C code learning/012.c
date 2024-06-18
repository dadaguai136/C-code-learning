/*小游戏 玩家随机输出一个0到9的数字和系统随机给定的数字比大小*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char start='y';
	int s;//计数
	int x;//随机数
	int n;//输入数
	while(start=='y'||start=='Y')
	{
		s=1;
		x=rand()%10;
		while(1)
		{
			scanf("%d",&n);
			s++;
			if(s>6)
			{
				printf("Game failed and ended\n");
				break;
			}
			if(n>x)
			{
				printf("The number entered is too large\n");
			}
			else if(n==x)
			{
				printf("Congratulations on your success!\n");
				break;
			}
			else
			{
				printf("You failed\n");
			}
		}
		printf("Do you want to try again?\n");
		printf("Please enter y or Y to start the game\n");
		while((start=getchar())=='\n');
	}
}
