long long numberOfWays(char* s) {
    long long ways = 0;
    long long leftZeros = 0, leftOnes = 0, rightZeros = 0, rightOnes = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] == '0') {
            rightZeros++;
        } else {
            rightOnes++;
        }
    }
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            if (s[i - 1] == '0') {
                leftZeros++;
            } else {
                leftOnes++;
            }
        }
        if (s[i] == '0') {
            rightZeros--;
            ways += leftOnes * rightOnes;
        } else {
            rightOnes--;
            ways += leftZeros * rightZeros;
        }
    }
    return ways;
}
