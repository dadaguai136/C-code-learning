int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int findDuplicate(int* nums, int n) {
	qsort(nums, n, sizeof(int), cmp);
	for (int i = 1; i < n; i++) 
	{
		if (nums[i] == nums[i - 1]) 
		{
			return nums[i];
		}
	}
	return -1;
}
int hash[100001] = {0};
int findDuplicate(int* nums, int n) {//优化
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < n; i++) {
		if (hash[nums[i]]) {
			return nums[i];
		}
		hash[nums[i]] = 1;
	}
	return -1;
}
int findDuplicate(int* nums, int n) {//优化
	int low = 0, fast = 0;
	do {
		low = nums[low];
		fast = nums[nums[fast]];
	} while (low != fast);
	low = 0;
	while (low != fast) {
		low = nums[low];
		fast = nums[fast];
	}
	return low;
	//初等数论的同余定理
}
