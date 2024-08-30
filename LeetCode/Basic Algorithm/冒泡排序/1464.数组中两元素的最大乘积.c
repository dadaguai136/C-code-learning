void BubbleSort(int *a, int n) {
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
int maxProduct(int* nums, int numsSize) {
	BubbleSort(nums, numsSize);
	return (nums[numsSize - 1] - 1) * (nums[numsSize - 2] - 1);
}
