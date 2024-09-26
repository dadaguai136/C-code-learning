char** printVertically(char* s, int* returnSize) {
	char** word = (char**)calloc(200, sizeof(char*));
	for (int i = 0; i < 200; i++) {
		word[i] = (char*)calloc(200, sizeof(char));
	}
	int index = 0;
	const char space[2] = " ";
	char* token;
	/* 获取第一个子字符串 */
	token = strtok(s, space);

	/* 继续获取其他的子字符串 */
	while (token != NULL) {
		printf("%s\n", token);
		strcpy(word[index++], token);
		token = strtok(NULL, space);
	}
	char** ans = (char**)calloc(200, sizeof(char*));
	for (int i = 0; i < 200; i++) {
		ans[i] = (char*)calloc(200, sizeof(char));
	}
	int maxLen = 0;
	for (int i = 0; i < index; i++) {
		printf("%d\n", strlen(word[i]));
		if (strlen(word[i]) >= maxLen) {
			maxLen = strlen(word[i]);
		}
	}

	for (int i = 0; i < maxLen; i++) {
		for (int j = 0; j < index; j++) {
			if (isupper(word[j][i])) {
				ans[i][j] = word[j][i];
			}
			else {
				ans[i][j] = ' ';
			}
		}
        for (int k = strlen(ans[i]) - 1; k >= 0; k--) {
            if (isupper(ans[i][k])) {
                break;
            } else {
                ans[i][k] = '\0';
            }
        }
	}
	*returnSize = maxLen;
	return ans;
}
