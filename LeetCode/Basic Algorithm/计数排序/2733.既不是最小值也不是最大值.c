void CountingSort(int *a, int size)
 {
	int cnt[101] = {0};
	for (int i = 0; i < size; i++)
	{
		cnt[a[i]]++;
	}
	int Asize = 0;
	for (int i = 0; i < 101; i++) 
	{
		while (cnt[i]) 
		{
			a[Asize++] = i;
			cnt[i]--;
		}
	}
}
int findNonMinOrMax(int* nums, int numsSize) {
	CountingSort(nums, numsSize);
	for (int i = 0; i < numsSize; i++) 
	{
		if (nums[i] == nums[0] || nums[i] == nums[numsSize - 1]) 
		{
			continue;
		}
		return nums[i];
	}
	return -1;
}
