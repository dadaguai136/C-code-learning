void InsertSort(int *a, int n) 
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)
	 {
		temp = a[i];
		for (j = i - 1; j >= 0; j--) 
		{
			if (temp < a[j]) 
			{
				a[j + 1] = a[j];
			}
			 else 
			{
				break;
			}
		}
		a[j + 1] = temp;
	}
}
double profun(int *arr, int arrSize, int cnt) 
{
	InsertSort(arr, arrSize);
	double ans = 0;
	for (int i = cnt; i < arrSize - cnt; i++) 
	{
		ans += arr[i];
	}
	return ans / (arrSize - 2 * cnt);
}
double average(int* salary, int salarySize) {
	return profun(salary, salarySize, 1);
}
