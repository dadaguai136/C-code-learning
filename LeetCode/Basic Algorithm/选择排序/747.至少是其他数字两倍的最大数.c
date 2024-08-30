void SelectSort(int *a, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		int minidx = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[j] < a[minidx]) 
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
int dominantIndex(int* nums, int numsSize) {
	int maxidx = 0;
	for (int i = 0; i < numsSize; i++) 
	{
		if (nums[i] > nums[maxidx]) 
		{
			maxidx = i;//记录最大数下标
		}
	}
	SelectSort(nums, numsSize);
	if (nums[numsSize - 1] >= nums[numsSize - 2] * 2) //判断是否至少是第二大数的两倍
	{
		return maxidx;
	}
	return -1;
}
