bool Check(int *a, int n, int m, int v) 
{
	int sum = 0;
	for (int i = 0; i < n; i++) 
	{
		sum += a[i];
		if (a[i] > v) 
		{
			return false;
		}
		if (sum > v) 
		{
			m--;
			sum = a[i];
			if (!m) 
			{
				return false;
			}
		}
	}
	return true;
}
int splitArray(int* a, int n, int m) {
	int l = 0, r = 10000000000;
	int ans = -1;
	while (l <= r) //¶ş·ÖÃ¶¾Ù
	{
		int mid = (l + r) >> 1;
		if (Check(a, n, m, mid)) 
		{
			ans = mid;
			r = mid - 1;
		} 
		else 
		{
			l = mid + 1;
		}
	}
	return ans;
}
