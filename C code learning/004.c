/*����һ����С����ĳ齱�ĳ���*/
#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int *a,int n)
{
    int i,j;
    int temp;
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void BubbleSort1(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%02d ",a[i]);//��λ��ǰ��0
	}
	printf("\b-The winning number is %02d\n",rand()%(16)+1);//�н�������Ϊ
}
int Random1(int a[],int x,int n)
{
	for(int i=0;i<=n;i++)
	{
		if(x==a[i])//��ϵͳ���ֵ
		{
			return 1;
		}
	}
	return 0;
}
void Random(int a[],int n)
{
	int x;
	for(int i=0;i<n;i++)
	{
		while(Random1(a,x=rand()%33+1,i)==1);//�������x ����ֵΪ1ʱˢ��x
		a[i]=x;//ȷ�����ֵx
	}
	BubbleSort(a,n);//ð��������
}
int main()
{
	int a[6];
	for(int i=0;i<10;i++)
	{
		Random(a,6);
		Print(a,6);
	}
}
