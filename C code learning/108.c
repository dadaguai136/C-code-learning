#include<stdio.h>
int Judge(char n)
{
	return n>='0'&&n<='9';
}
void Sort(char a[],int flag)
{
	char *p,*q,t;
	int x;
	for(p=a;*(p+1);p++)
	{
		for(q=p+1;*q;q++)
		{
			x=*p*flag>*q*flag&&!Judge(*p)&&!Judge(*q);
			if(x)
			{
				t=*p;
				*p=*q;
				*q=t;
			}
		}
	}
}
int main()
{
	printf("Sort the letters in the character array\n");
	char a[]="a3ajk4b4dk948d93q";
	Sort(a,1);
	puts(a);
}
