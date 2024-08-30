int maximizeSum(int* nums, int numsSize, int k) 
{
	int ret = 0;
	while (k--) 
	{
		int maxindex = 0;
		for (int i = 0; i < numsSize; i++) 
		{
			if (nums[i] > nums[maxindex])
			{
				
				maxindex = i;
			}
		}
		ret += nums[maxindex];
		nums[maxindex] += 1;
	}
	return ret;
}
