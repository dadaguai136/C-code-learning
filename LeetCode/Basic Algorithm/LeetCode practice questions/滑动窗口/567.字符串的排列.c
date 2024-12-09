bool checkInclusion(char* s1, char* s2) {
    int n=strlen(s1),m=strlen(s2);
    if(n>m)
    {
        return false;
    }
    int cnt[256];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        --cnt[s1[i]-'a'];
    }
    int left=0;
    for(int right=0;right<m;++right)
    {
        int x=s2[right]-'a';
        ++cnt[x];
        while(cnt[x]>0)
        {
            --cnt[s2[left]-'a'];
            ++left;
        }
        if(right-left+1==n)
        {
            return true;
        }
    }
    return false;
}




bool checkInclusion(char* s1, char* s2) {
    int n=strlen(s1);
    int m=strlen(s2);
    if(n>m)
    {
        return false;
    }
    int hash[26];
    memset(hash,0,sizeof(char));
    for(int i=0;i<n;i++)
    {
        hash[s1[i]-'a']--;
        hash[s2[i]-'a']++;
    }
    int diff=0;
    for(int i=0;i<26;i++)
    {
        if(hash[i]!=0)
        {
            diff++;
        }
    }
    if(diff==0)
    {
        return true;
    }
    for(int i=n;i<m;i++)
    {
        char x=s2[i],y=s2[i-n];
        if(x==y)
        {
            continue;
        }
        if(hash[x-'a']==0)
        {
            diff++;
        }
        ++hash[x-'a'];
        if(hash[x-'a']==0)
        {
            diff--;
        }
        if(hash[y-'a']==0)
        {
            diff++;
        }
        --hash[y-'a'];
        if(hash[y-'a']==0)
        {
            diff--;
        }
        if(diff==0)
        {
            return true;
        }
    }
    return false;
}




int check(char *hash1,char *hash2)
{
    for(int i=0;i<26;i++)
    {
        if(hash1[i]!=hash2[i])
        {
            return 0;
        }
    }
    return 1;
}
bool checkInclusion(char* s1, char* s2) {
    int n=strlen(s1);
    int m=strlen(s2);
    if(n>m)
    {
        return false;
    }
    char hash1[26],hash2[26];
    memset(hash1,0,sizeof(char));
    memset(hash2,0,sizeof(char));
    for(int i=0;i<n;i++)
    {
        hash1[s1[i]-'a']++;
        hash2[s2[i]-'a']++;
    }
    if(check(hash1,hash2))
    {
        return true;
    }
    for(int i=n;i<m;i++)
    {
        hash2[s2[i]-'a']++;
        hash2[s2[i-n]-'a']--;
        if(check(hash1,hash2))
        {
            return true;
        }
    }
    return false;
}
