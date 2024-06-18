#include<stdio.h>
#include<math.h>
int Fun1(long int p,int q)
{
	int t=1;
	int q1=q;
	while(q)
	{
		t=t*10;
		q=q/10;
	}
	if(p%t==q1)
	{
		return 1;
	}
	return 0;
}
int Fun(long int n)
{
	long int m;
	m=sqrt(n);
	if(m*m!=n)
	{
		return 0;
	}
	if(Fun1(n,m))
	{
		return 1;
	}
	return 0;
}
int main()
{
	for(long int n=1;n<1000000;n++)
	{
		if(Fun(n))
		{
			printf("%ld\n",n);
		}
	}
}
