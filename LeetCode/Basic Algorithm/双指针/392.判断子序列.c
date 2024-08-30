bool isSubsequence(char* s, char* t) {
	int i = 0, j = 0;
	while (s[i] && t[j]) 
	{
		if (s[i] == t[j]) 
		{
			i++;
		}
		j++;
	}
	return s[i] == '\0';//判断是否是子序列
}
