#include<stdio.h>
int Minimum(int a[],int n)//��С��
{
	int min;
	if(n==1)
	{
		return a[0];
	}
	min=Minimum(a+1,n-1);
	if(a[0]>min)//��ÿ�εݹ�ʱ�ĵ�һ�����Ƚ�
	{
		return min;
	}
	return a[0];
}
int Greatest_Common_Divisor(int a[],int n)
{
	int i;
	int min=Minimum(a,n);
	while(min)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]%min!=0)
			{
				break;
			}
		}
		if(i==n)//��ѭ�����ط���min�ݼ�
		{
			return min;
		}
		min--;
	}
}
int main()
{
	int a[]={36,12,18,24};
	printf("%d",Greatest_Common_Divisor(a,4));
}
