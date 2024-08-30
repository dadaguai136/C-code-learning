int cmp(const void *a, const void *b) 
{
	int val = *(int *)a;
	int vbl = *(int *)b;
	return val > vbl ? 1 : -1;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int temp[10001];
	memcpy(temp, nums, sizeof(int)*numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);
	int l = 0;
	int r = numsSize - 1;
	while (l < r) 
	{
		int sum = nums[l] + nums[r];
		if (sum > target) 
		{
			r--;
		} else if (sum < target) 
		{
			l++;
		} 
		else 
		{
			break;
		}
	}
	int *ret = (int *)malloc(sizeof(int) * 2);
	if (l == r) 
	{
		*returnSize = 0;
		return ret;
	}
	for (int i = 0; i < numsSize; i++) 
	{
		if (temp[i] == nums[l]) 
		{
			l = i;
			break;
		}
	}
	for (int i = 0; i < numsSize; i++) 
	{
		if (temp[i] == nums[r] && i != l) 
		{
			r = i;
			break;
		}
	}
	if (l > r) //原数组中的下标可能存在l>r
	{
		int t;
		t = l;
		l = r;
		r = t;
	}
	*returnSize = 2;
	ret[0] = l;
	ret[1] = r;
	return ret;
}
