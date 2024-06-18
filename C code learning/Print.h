void Int_Print(int a[],int n)
{
	for(int *p=a;p<a+n;p++)
	{
		printf("%3d",*p);
	}
}
void Char_Print(char a[])
{
	while(*a)
	{
		printf("%c",*a);
		a++;
	}
}
