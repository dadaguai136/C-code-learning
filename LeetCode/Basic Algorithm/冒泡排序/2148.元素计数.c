void BubbleSort(int *a, int n)
 {
	int i, j;
	int temp;
	for (i = n - 1; i > 0; i--)
	 {
		for (j = 0; j < i; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int countElements(int* nums, int numsSize) {
	BubbleSort(nums, numsSize);
	int ans = 0;
	for (int i = 0; i < numsSize; i++) 
	{
		if (nums[i] == nums[0] || nums[i] == nums[numsSize - 1]) 
		{
			continue;//排除最小数和最大数
		}
		ans++;
	}
	return ans;
}
