int cmp(const void *a, const void *b) {
	int va = *(int *)a;
	int vb = *(int *)b;
	return va < vb ? -1 : 1;
}
long long CountLessThan(int *nums, int n, int val) {
	int l = 0, r = n - 1;
	long long ans = 0;
	while (l < r) 
	{
		int sum = nums[l] + nums[r];
		if (sum <= val) 
		{
			ans += r - l;
			l++;
		} 
		else 
		{
			r--;
		}
	}
	return ans;
}
long long countFairPairs(int* nums, int n, int lower, int upper) {
	qsort(nums, n, sizeof(int), cmp);
	long long other = CountLessThan(nums, n, lower - 1);
	long long all = CountLessThan(nums, n, upper);
	return all - other;
}
