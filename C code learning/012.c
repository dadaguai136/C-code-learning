/*С��Ϸ ���������һ��0��9�����ֺ�ϵͳ������������ֱȴ�С*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char start='y';
	int s;//����
	int x;//�����
	int n;//������
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
