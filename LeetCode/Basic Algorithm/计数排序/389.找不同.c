void CountingSort(char *k)//计数排序
 {
	int cnt[256] = {0};//哈希表
	for (int i = 0; k[i]; i++) 
	{
		cnt[k[i]]++;
	}
	int Ksize = 0;
	for (int i = 0; i < 256; i++) //遍历哈希表
	{
		while (cnt[i])
		 {
			k[Ksize++] = i;
			cnt[i]--;
		}
	}
	k[Ksize] = 0;
}
char findTheDifference(char* s, char* t) {
	CountingSort(s);
	CountingSort(t);
	int i;
	for (i = 0; s[i]; i++)
	{
		if (s[i] != t[i]) 
		{
			return t[i];
		}
	}
	return t[i];
}
