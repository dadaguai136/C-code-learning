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
int minimumDifference(int* nums, int numsSize, int k) {
	InsertSort(nums, numsSize);
	int ret = 1000000;
	for(int i = 0; i + k - 1 < numsSize; i++)
	{
		int ans = nums[i + k - 1] - nums[i];//×îÏÂ²îÖµ
		if (ret > ans) 
		{
			ret = ans;
		}
	}
	return ret;
}
