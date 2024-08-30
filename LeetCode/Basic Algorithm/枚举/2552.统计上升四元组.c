#include<stdio.h>
long long countQuadruplets(int *a, int n) { //O(n^4)
	int i, j, k, l;
	long long ans = 0;
	for (i = 0; i < n; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			for (k = j + 1; k < n; k++) 
			{
				for (l = k + 1; l < n; l++) 
				{
					if (a[i] < a[k] && a[k] < a[j] && a[j] < a[l]) 
					{
						ans++;
					}
				}
			}
		}
	}
	return ans;
}
long long countQuadruplets(int *a, int n) { //优化后的O(n^4)
	int i, j, k, l;
	long long ans = 0;
	for (i = 0; i < n; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			for (k = j + 1; k < n; k++) 
			{
				if (a[i] >= a[k]) 
				{
					continue;
				}
				if (a[k] >= a[j]) 
				{
					continue;
				}
				for (l = k + 1; l < n; l++) 
				{
					if (a[j] < a[l]) 
					{
						ans++;
					}
				}
			}
		}
	}
	return ans;
}
long long countQuadruplets(int *a, int n) 
{ //O(n^3)
	int i, j, k, l;
	long long ans = 0;
	for (j = 1; j < n; j++) 
	{
		for (k = j + 1; k < n; k++) 
		{
			if (a[k] >= a[j]) 
			{
				continue;
			}
			int less = 0;
			for (i = 0; i < j; i++) 
			{
				if (a[i] < a[k]) 
				{
					++less;
				}
			}
			int bigger = 0;
			for (l = k + 1; l < n; l++) 
			{
				if (a[l] > a[j]) 
				{
					bigger++;
				}
			}
			ans += less * bigger;
		}
	}
	return ans;
}
#define maxn 4001
int less[maxn][maxn], bigger[maxn][maxn];
//less[x][y]代表0到x-1的数中，小于y的数
//bigger[x][y]代表x+1到n-1的数中，大于y的个数
//对于任意j<k，且nums[k]<nums[j]
//累加less[j][nums[k]*bigger[k][nums[j];
long long countQuadruplets(int* nums, int numsSize) 
{ //O(n^2)
	int i, j, x;
	for (i = 1; i <= numsSize; i++) 
	{
		less[0][i] = 0;
	}
	for (i = 1; i < numsSize; i++) 
	{
		x = nums[i - 1];
		for (j = 1; j <= numsSize; j++) 
		{
			if (x < j) 
			{
				less[i][j] = less[i - 1][j] + 1;
			} 
			else 
			{
				less[i][j] = less[i - 1][j];
			}
		}
	}
	for (i = 1; i <= numsSize; i++) 
	{
		bigger[numsSize - 1][i] = 0;
	}
	for (i = numsSize - 2; i >= 0; i--) 
	{
		x = nums[i + 1];
		for (j = 1; j <= numsSize; j++) 
		{
			if (x > j) 
			{
				bigger[i][j] = bigger[i + 1][j] + 1;
			} 
			else 
			{
				bigger[i][j] = bigger[i + 1][j];
			}
		}
	}
	long long ans = 0;
	int k;
	for (j = 0; j < numsSize; j++) 
	{
		for (k = j + 1; k < numsSize; k++) 
		{
			if (nums[k] < nums[j]) 
			{
				ans += less[j][nums[k]] * bigger[k][nums[j]];
			}
		}
	}
	return ans;
}
