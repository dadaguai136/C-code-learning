#define FIN -999999
int thirdMax(int* nums, int numsSize) 
{
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) 
	{
		if (max < nums[i]) 
		{
			max = nums[i];
		}
	}
	int submax = FIN;
	for (int i = 0; i < numsSize; i++) 
	{
		if (submax == FIN) 
		{
			if (nums[i] < max) 
			{
				submax = nums[i];
			}
		} 
		else 
		{
			if (nums[i] < max && nums[i] > submax) 
			{
				submax = nums[i];
			}
		}
	}
	if (submax == FIN) 
	{
		return max;
	}
	int trpmax = FIN;
	for (int i = 0; i < numsSize; i++) 
	{
		if (trpmax == FIN) 
		{
			if (nums[i] < max && nums[i] < submax) 
			{
				trpmax = nums[i];
			}
		} 
		else 
		{
			if (nums[i] < max && nums[i] < submax && nums[i] > trpmax) 
			{
				trpmax = nums[i];
			}
		}
	}
	if (trpmax == FIN) 
	{
		return max;
	}
	return trpmax;
}
