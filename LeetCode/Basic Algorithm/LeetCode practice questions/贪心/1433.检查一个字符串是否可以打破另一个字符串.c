
void sort(char *str) {
    int hash[26] = {0};
    for (char *p = str; *p ; p++) { // ��¼���е��ַ� 
        hash[*p - 'a']++;
    }
    char *p = str;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < hash[i]; j++) {
            *p++ = i + 'a';
        }
    }
}

bool checkIfCanBreak(char * s1, char * s2){
    sort(s1),sort(s2);  // ������ 
    printf("%s\n%s",s1,s2);
    char *p = s1,*q = s2;
    for (; *p && *p >= *q; p++,q++);
    if (*p == 0) return true;
    for (; *s1 && *s1 <= *s2; s1++,s2++);
    return *s1 == 0;
}
