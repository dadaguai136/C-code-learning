#include<stdio.h>
#include<malloc.h>
int *One_Two(int a[],int n)
{
	int *one,*two;
	int *p;
	int *ret=(int *)malloc(sizeof(int)*2);
	one=two=a;
	for(p=a;p<a+n;p++)
	{
		if(*one<*p)
		{
			one=p;
		}
	}
	ret[0]=*one;
	while(*two==*one&&two<a+n)
	{
		two++;
	}
	if(two==a+n)
	{
		printf("There is no second largest number");
	}
	for(p=a;p<a+n;p++)
	{
		if(*two<*p&&*p!=*one)
		{
			two=p;
		}
	}
	ret[1]=*two;
	return ret;
}
void One_Two1(int *a,int n)
{
	int *one,*two;
	int *p;
	one=two=a;
	for(p=a;p<a+n;p++)
	{
		if(*one>*p)
		{
			one=two=p;
		}
	}
	for(p=a;p<a+n;p++)
	{
		if(*one<*p)
		{
			two=one;
			one=p;
		}
		if(*one!=*p&&*two<*p)
		{
			two=p;
		}
	}
	printf("%d and %d",*one,*two);
}
int main()
{
	printf("Finding the maximum and second largest numbers in an array\n");
	int a[]={1,57,98,2,64,27,74,32,86,99,88,99,99,2,41};
	int *p;
	p=One_Two(a,sizeof(a)/4);
	printf("%d %d\n",*p,*(p+1));
	One_Two1(a,sizeof(a)/4);
}
