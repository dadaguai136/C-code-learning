int lowe(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int maxVowels(char* s, int k) {
    int loweCount=0;
    for(int i=0;i<k;i++)
    {
        if(lowe(s[i]))
        {
            loweCount++;
        }
    }
    int ans=loweCount;
    for(int i=k;s[i];i++)
    {
        loweCount+=lowe(s[i])-lowe(s[i-k]);
        ans=fmax(ans,loweCount);
    }
    return ans;
}




#define MAX(a,b) ((b)>(a)?(b):(a))
int maxVowels(char* s, int k) {
    int ans=0,vowel=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            vowel++;
        }
        if(i<k-1)
        {
            continue;
        }
        ans=MAX(ans,vowel);
        char out=s[i-k+1];
        if(out=='a'||out=='e'||out=='i'||out=='o'||out=='u')
        {
            vowel--;
        }
    }
    return ans;
}
