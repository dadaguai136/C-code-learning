int partitionString(char* s) {
	int hash[26];
	int cnt = 0;
	memset(hash, 0, sizeof(hash));
	for (int i = 0; s[i]; i++) 
	{
		if (hash[s[i] - 'a']) //判断哈希值
		{
			cnt++;//划分一刀
			memset(hash, 0, sizeof(hash));//重置哈希值
		}
		hash[s[i] - 'a'] = 1;//哈希值为真
	}
	cnt++;//总子数组
	return cnt;
}
