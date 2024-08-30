int Getmaxlen(int n, int *str) {//典型枚举效率最慢的算法
	int ans = 0, i, j, len;
	int l, r;
	memset(hash, 0, sizeof(hash));
	for (i = 0; i < n, i++) 
	{
		j = i;
		memset(hash, false, sizeof(hash));
		while (j < n && !hash[str[j]]) 
		{
			hash[str[j]] = true;
			len = j - i + 1;
			if (len > ans) 
			{
				ans = len;
				l = i;
				r = j;
				j++;
			}
		}
	}
	return ans;
}
int lengthOfLongestSubstring(char* s) {//优化后O(n)
	int n = strlen(s);
	int max = 0;
	int hash[256] = {0};
	for (int i = 0, j = -1; j < n - 1;) {
		j++;
		hash[s[j]]++;
		while (hash[s[j]] > 1) {
			hash[s[i]]--;
			i++;
		}
		if (j - i + 1 > max) {
			max = j - i + 1;
		}
	}
	return max;
}
