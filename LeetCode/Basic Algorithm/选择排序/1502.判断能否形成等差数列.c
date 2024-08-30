void SelectSort(int *a, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		int minidx = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[minidx] < a[j]) 
			{
				minidx = j;
			}
		}
		int temp;
		temp = a[i];
		a[i] = a[minidx];
		a[minidx] = temp;
	}
}
bool canMakeArithmeticProgression(int* arr, int arrSize) {
	SelectSort(arr, arrSize);
	int d = arr[1] - arr[0];//¹«²î
	for (int i = 2; i < arrSize; i++) 
	{
		if (arr[i] - arr[i - 1] != d) 
		{
			return false;
		}
	}
	return true;
}
