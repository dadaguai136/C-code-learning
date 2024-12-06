void fun(char *a,int n)
{
    int i=0,j=n;
    while(i<j)
    {
        char c=a[i];
        a[i]=a[j];
        a[j]=c;
        i++;
        j--;
    }
}
char* reversePrefix(char* word, char ch) {
    int i=0;
    while(word[i]&&word[i]!=ch)
    {
        i++;
    }
    if(word[i]==0)
    {
        return word;
    }
    fun(word,i);
    return word;
}




char* reversePrefix(char* word, char ch) {
    int i=0;
    while(word[i]!=ch&&word[i]!='\0')
    {
        i++;
    }
    if(word[i]=='\0')
    return word;
    int left=0;
    int right=i;
    while(right>=left)
    {
        char tmp=word[left];
        word[left]=word[right];
        word[right]=tmp;
        left++;
        right--;
    }
    return word;
}




char * reversePrefix(char * word, char ch){
    char *p2 = strchr(word, ch);
    if (p2 != NULL) {
        char *p1 = word;
        while (p1 < p2) {
            char tmp = *p1;
            *p1 = *p2;
            *p2 = tmp;
            p1++;
            p2--;
        }
    }
    return word;
}
