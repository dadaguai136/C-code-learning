#include<stdio.h>
int Judgment_Prime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int Maximum_Two_Digit_Prime(long n)
{
	int pre;
	int cur;
	if(n<10)
	{
		return 0;
	}
	pre=Maximum_Two_Digit_Prime(n/10);
	cur=n%100;
	if(Judgment_Prime(cur)==0)
	{
		return pre;
	}
	if(pre<cur)
	{
		return cur;
	}
	return pre;
}
int main()
{
	printf("The two largest prime number in a series of numbers\n");
	long n;
	scanf("%ld",&n);
	printf("%d",Maximum_Two_Digit_Prime(n));
}
