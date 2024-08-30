void reverseString(char* s, int sSize) {
	int i = 0, j = sSize - 1;
	while (i < j) 
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
