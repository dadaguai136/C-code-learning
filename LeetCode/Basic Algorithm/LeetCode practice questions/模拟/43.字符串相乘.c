#define MAX_LEN 200

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) {
        char* result = malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int* result = (int *) calloc(len1 + len2, sizeof(int));
    // 逐位相乘
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];

            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    // 将结果转换成为字符串
    char* retStr = (char *) malloc(len1 + len2 + 1);
    if (!retStr) {
        free(result);
    }
    int i = 0;
    int index = 0;
    while (i < len2 + len1 && result[i] == 0) {
        i++;
    }

    while (i < len1 + len2) {
        retStr[index++] = result[i++] + '0';
    }
    retStr[index] = '\0';
    free(result);

    return retStr;
}












char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = malloc(sizeof(char) * (i + j + 5));
    int ansLen = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[ansLen++] = result % 10;
        add = result / 10;
        i--;
        j--;
    }
    for (int i = 0; i < ansLen / 2; i++) {
        char t = ans[i];
        ans[i] = ans[ansLen - 1 - i];
        ans[ansLen - 1 - i] = t;
    }
    for (int i = 0; i < ansLen; i++) {
        ans[i] += '0';
    }
    ans[ansLen++] = 0;
    return ans;
}

char* multiply(char* num1, char* num2) {
    int m = strlen(num1), n = strlen(num2);
    char* ans = malloc(sizeof(char) * 2);
    ans[0] = '0', ans[1] = 0;
    if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
        return ans;
    }
    for (int i = n - 1; i >= 0; i--) {
        char* curr = malloc(sizeof(char) * (n + m + 5));
        int currLen = 0;
        int add = 0;
        for (int j = n - 1; j > i; j--) {
            curr[currLen++] = 0;
        }
        int y = num2[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int x = num1[j] - '0';
            int product = x * y + add;
            curr[currLen++] = product % 10;
            add = product / 10;
        }
        while (add != 0) {
            curr[currLen++] = add % 10;
            add /= 10;
        }
        for (int i = 0; i < currLen / 2; i++) {
            char t = curr[i];
            curr[i] = curr[currLen - 1 - i];
            curr[currLen - 1 - i] = t;
        }
        for (int i = 0; i < currLen; i++) {
            curr[i] += '0';
        }
        curr[currLen++] = 0;
        char* tmp = addStrings(ans, curr);
        free(ans), free(curr);
        ans = tmp;
    }
    return ans;
}
