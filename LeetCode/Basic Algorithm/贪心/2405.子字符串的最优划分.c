int partitionString(char* s) {
	int hash[26];
	int cnt = 0;
	memset(hash, 0, sizeof(hash));
	for (int i = 0; s[i]; i++) 
	{
		if (hash[s[i] - 'a']) //�жϹ�ϣֵ
		{
			cnt++;//����һ��
			memset(hash, 0, sizeof(hash));//���ù�ϣֵ
		}
		hash[s[i] - 'a'] = 1;//��ϣֵΪ��
	}
	cnt++;//��������
	return cnt;
}
