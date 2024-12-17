long long maximumSubsequenceCount(char* text, char* pattern) {
    long long res = 0, cnt1 = 0, cnt2 = 0;
    for (const char *c = text; *c; c++) {
        if (*c == pattern[1]) {
            res += cnt1;
            cnt2++;
        }
        if (*c == pattern[0]) {
            cnt1++;
        }
    }
    return res + (cnt1 > cnt2 ? cnt1 : cnt2);
}
