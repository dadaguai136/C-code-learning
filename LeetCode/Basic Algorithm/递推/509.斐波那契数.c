int fib(int n) {
	int a[31] = {0, 1};
	int i;
	for (i = 2; i <= n; i++) 
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}
