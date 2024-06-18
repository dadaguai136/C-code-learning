#include<stdio.h>
int Continuous(int n)
{
	int a,b,c;
	a=n/100;
	b=n/10%10;
	c=n%10;
	if(a+1==b&&b+1==c)
	{
		return 1;
	}
	return 0;
}
int Contain(long m,long n)
{
	long k=1,s=n;
	while(s)
	{
		k=k*10;
		s=s/10;
	}
	if(m%k==n)
	{
		return 1;
	}
	return 0;
}
long Recursion(long n)
{
	long pre;
	if(n<100)
	{
		return 0;
	}
	pre=Recursion(n/10);
	if(pre==0)
	{
		if(Continuous(n%1000))
		{
			return n%1000;
		}
	}
	if(Contain(n/10,pre))
	{
		if(pre%10+1==n%10)
		{
			return pre*10+n%10;
		}
		return pre;
	}
}
long Recursion1(long n)
{
   long s,k=10,m,t=0;
   s=n;
   if(n<100)
   {
   	return 0;
   }
   while(s/10%10+1==s%10&&s)
   {
   	k=k*10;
   	s=s/10;
   }
   if(n%k>100)
   {
   	t=n%k;
   }
   m=Recursion1(n/k);
   if(m>t)
   {
   	return m;
   }
   return t;
}

int main()
{
	printf("Finding Continuous Numbers in Numbers\n");
	long n;
	scanf("%ld",&n);
	printf("%ld",Recursion1(n));
}
