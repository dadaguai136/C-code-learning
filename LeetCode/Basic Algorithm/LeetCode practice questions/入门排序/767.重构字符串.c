int max(int a,int b)
{
    return a>b?a:b;
}
char* reorganizeString(char* s) {
    int n=strlen(s);
    if(n<2)
    {
        return s;
    }
    int hash[26];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        hash[c-'a']++;
    }
    int maxCount=0;
    for(int i=0;i<26;i++)
    {
        maxCount=max(maxCount,hash[i]);
    }
    if(maxCount>(n+1)/2)
    {
        return "";
    }
    char *ret=malloc(sizeof(char)*(n+1));
    for(int i=0;i<n;i++)
    {
        ret[i]=' ';
    }
    ret[n]='\0';
    int evenIndex=0;
    int oddIndex=1;
    int half=n/2;
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        while(hash[i]>0&&hash[i]<=half&&oddIndex<n)
        {
            ret[oddIndex]=c;
            hash[i]--;
            oddIndex+=2;
        }
        while(hash[i]>0)
        {
            ret[evenIndex]=c;
            hash[i]--;
            evenIndex+=2;
        }
    }
    return ret;
}
