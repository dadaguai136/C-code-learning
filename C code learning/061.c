#include<stdio.h>
void Remove(char a[])
{
	char *p,*q;
	char *head=a;
	for(p=a;*p;p++)
	{
		for(q=a;q<p;q++)
		{
			if(*q==*p)
			{
				break;
			}
		}
		if(q==p)
		{
			*head++=*p;
		}
	}
	*head=0;
}
int main()
{
	printf("Remove duplicate characters from character arrays\n");
	char a[]="1747392364393922002";
	Remove(a);
	puts(a);
}
