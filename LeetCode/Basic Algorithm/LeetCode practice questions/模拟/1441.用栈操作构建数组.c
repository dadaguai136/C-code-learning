char ** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **res = (char **)malloc(sizeof(char *)*n*2);
    int prev = 0, pos = 0;
    for (int j = 0; j < targetSize; j++) {
        for (int i = 0; i < target[j] - prev - 1; i++) {
            res[pos] = (char *)malloc(sizeof(char) * 6);
            strcpy(res[pos++], "Push");
            res[pos] = (char *)malloc(sizeof(char) * 6);
            strcpy(res[pos++], "Pop");
        }
        res[pos] = (char *)malloc(sizeof(char) * 6);
        strcpy(res[pos++], "Push");
        prev = target[j];
    }
    *returnSize = pos;
    return res;
}
