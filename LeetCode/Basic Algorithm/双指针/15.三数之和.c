int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
	qsort(nums, n, sizeof(int), cmp);
	int base = 100;
	int **ret = (int **)malloc(sizeof(int *)*base);
	*returnColumnSizes = (int *)malloc(sizeof(int) * base);
	*returnSize = 0;
	int i, j, k;
	for (i = 0; i < n; i++) 
	{
		if (i > 0 && nums[i] == nums[i - 1]) 
		{
			continue;
		}
		j = i + 1;
		k = n - 1;
		while (j < k) 
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == 0) 
			{
				ret[*returnSize] = (int *)malloc(sizeof(int) * 3);
				(*returnColumnSizes)[*returnSize] = 3;
				ret[*returnSize][0] = nums[i];
				ret[*returnSize][1] = nums[j];
				ret[*returnSize][2] = nums[k];
				(*returnSize)++;
				if (*returnSize == base) 
				{
					base *= 2;
					ret = (int **)realloc(ret, sizeof(int *)*base);
					*returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * base);
				}
				int num1 = nums[j], num2 = nums[k];
				while (nums[j] == num1 && j < k) 
				{
					j++;
				}
				while (nums[k] == num2 && k > j) 
				{
					k--;
				}
			} 
			else if (sum < 0) 
			{
				j++;
			} 
			else 
			{
				k--;
			}
		}
	}
	return ret;
}
