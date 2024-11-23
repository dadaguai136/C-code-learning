char* largestOddNumber(char* num) {
    int len = strlen(num);
    if ((num[len-1] - '0') % 2 == 1) return num;
    
    int loc = len-1;
    while (loc >= 0) {
        int tmp = num[loc] - '0';
        if (tmp % 2 == 1) {
            char* res = malloc(sizeof(char) * (loc+2));
            res[loc+1] = '\0';
            for (int i =0 ; i <= loc; i++) {
                res[i] = num[i];
            }
            return res;
        } else loc--;
    }
    return "";
}
