#include<stdio.h>
#include<stdlib.h>//�������������ͷ�ļ�
void Random(int a[],int n)//������� ���������
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;//�����������
	}
}
void Print(int a[],int n)//��ӡ����
{
	for(int i=0;i<n;i++)
	{
		printf("original random array display %3d\n",a[i]);
		//ԭ���������ʾ
	}
}
void Restrict(int a[],int n)//���ƺ���
{
	int b[50];//���ֵ�ռ�
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=60)//���ƴ�С
		{
			b[j]=a[i];
			j++;
		}
	}
	for(int i=0;i<j;i++)
	{
		printf("Numbers greater than 60 are %d\n",b[i]);
		//����60������Ϊ
	}
	
}
int main()
{
	int a[50];
	Random(a,50);
	Print(a,50);
	Restrict(a,50);
}
