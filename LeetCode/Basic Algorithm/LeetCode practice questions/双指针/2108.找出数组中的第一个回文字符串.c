bool isTrue(char *a)
{
    int i=0,j=strlen(a)-1;
    while(i<j)
    {
        if(a[i]!=a[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
char* firstPalindrome(char** words, int wordsSize) {
    int *ret=(int *)malloc(sizeof(char)*101);
    int i;
    for(i=0;i<wordsSize;i++)
    {
        if(isTrue(words[i]))
        {
            strcpy(ret,words[i]);
            break;
        }
    }
    if(i==wordsSize)
    {
        return "";
    }
    return ret;
}




char* firstPalindrome(char** words, int wordsSize) {
    int j;
    for(int i=0;i<wordsSize;i++)
    {
        int n=strlen(words[i]);
        for(j=0;j<n/2;j++)
        {
            if(words[i][j]!=words[i][n-1-j])
            {
                break;
            }
        }
        if(j==n/2)
        {
            return words[i];
        }
    }
    return "";
}




char* firstPalindrome(char** words, int wordsSize) {
    for(int i=0;i<wordsSize;i++)
    {
        bool flag=true;
        char *word=words[i];
        int n=strlen(word);
        for(int j=0;j<n/2;j++)
        {
            if(word[j]!=word[n-1-j])
            {
                flag=false;
            }
        }
        if(flag)
        {
            return words[i];
        }
    }
    char *empty="";
    return empty;
}
