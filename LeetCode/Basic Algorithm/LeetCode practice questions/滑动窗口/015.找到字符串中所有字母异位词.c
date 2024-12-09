

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int sLen=strlen(s);
    int pLen=strlen(p);
    *returnSize=0;
    int *ans=(int *)malloc(sizeof(int)*sLen);
    if(sLen<pLen)
    {
        return NULL;
    }
    int hash[26];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<pLen;i++)
    {
        hash[s[i]-'a']++;
        hash[p[i]-'a']--;
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
        ans[(*returnSize)++]=0;
    }
    for(int i=0;i<sLen-pLen;i++)
    {
        char x=s[i+pLen],y=s[i];
        if(hash[x-'a']==0)
        {
            ++diff;
        }
        hash[x-'a']++;
        if(hash[x-'a']==0)
        {
            --diff;
        }
        if(hash[y-'a']==0)
        {
            ++diff;
        }
        --hash[y-'a'];
        if(hash[y-'a']==0)
        {
            --diff;
        }
        if(diff==0)
        {
            ans[(*returnSize)++]=i+1;
        }
    }
    return ans;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool check(int *sHash,int *pHash)
 {
    for(int i=0;i<26;i++)
    {
        if(sHash[i]!=pHash[i])
        {
            return false;
        }
    }
    return true;
 }
int* findAnagrams(char * s, char * p, int* returnSize){
    int sLen=strlen(s),pLen=strlen(p);
    *returnSize=0;
    int *ans=(int *)malloc(sizeof(int)*sLen);
    if(sLen<pLen)
    {
        return -1;
    }
    int size=0;
    int sHash[26],pHash[26];
    memset(sHash,0,sizeof(sHash));
    memset(pHash,0,sizeof(pHash));
    for(int i=0;i<pLen;i++)
    {
        sHash[s[i]-'a']++;
        pHash[p[i]-'a']++;
    }
    if(check(sHash,pHash))
    {
        ans[size++]=0;
    }
    for(int i=0;i<sLen-pLen;i++)
    {
        sHash[s[i]-'a']--;
        sHash[s[i+pLen]-'a']++;
        if(check(sHash,pHash))
        {
            ans[size++]=i+1;
        }
    }
    *returnSize=size;
    return ans;
}




int* findAnagrams(char *s, char *p, int *returnSize){
    int i,j;
    int len_1=strlen(s);
    int len_2=strlen(p);
    int *res=(int*)malloc(sizeof(int)*(len_1+1));
    memset(res,'\0',sizeof(int)*(len_1+1));
    *returnSize=0;
    if(len_1<len_2)
    {
        return res;
    }

    int map1[26],map2[26];
    memset(map1,0,sizeof(map1));
    memset(map2,0,sizeof(map2));
    for(i=0;i<len_2;i++)
    {
        map2[p[i]-'a']++;
    }
    for(i=0;i<len_2;i++)
    {
        map1[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(map1[i]!=map2[i])
        {
            break;
        }
    }
    if(i==26)
    {
        res[*returnSize]=0;
        *returnSize+=1;
    }
    for(i=0;i<len_1-len_2;i++)
    {
        map1[s[i]-'a']-=1;
        map1[s[i+len_2]-'a']+=1;
        for(j=0;j<26;j++)
        {
            if(map1[j]!=map2[j])
            {
                break;
            }
        }
        if(j==26)
        {
            res[*returnSize]=i+1;
            *returnSize+=1;
        }
    }
    res[*returnSize]='\0';
    return res;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
*int* findAnagrams：寻找p在s中元素相同的子字符串
char * s：比较字符串
char * p：目标字符串
int* returnSize：返回值长度
返回值：相同元素的初始下标
*/
int* findAnagrams(char * s, char * p, int* returnSize){
    int i,j;
    int p_len = strlen(p);
    int s_len = strlen(s);
    *returnSize=0;
    if(s_len < p_len)
    {
        return NULL;
    }
    int a[26] = {0};
    int b[26] = {0};
    int len = 0;
    for(i = 0; i < p_len; i++)//对p进行遍历赋值
    {
        b[p[i] - 'a']++;
    }
    int * ans = malloc(sizeof(int) * 30000);
    for(i = 0, j = 0; i < s_len && j < s_len; )//移动滑动窗口
    {
        if(a[s[i] - 'a'] < b[s[i] - 'a'])//当前位置的字符是p中元素，并且还可以再添加起码一个
        {
            a[s[i] - 'a']++;//
            len++;//滑动窗口大小加一
            i++;//进行向滑动窗口添加元素
            if(len == p_len)//滑动窗口的长度正好等于p的长度，保存i的初始值
            {
               ans[(*returnSize)++] = i-p_len; //i的初始值等于当前位置-滑动窗口大小+1
            }
            
        }
        else//当前元素不是p中元素或者是p中元素，但是这个元素多了
        {
            //我们要缩小滑动窗口，起码把当前这个多的元素踢出我们滑动窗口
            len--;//滑动窗口减少了一个元素，大小也需要减少1
            a[s[j] - 'a']--;
            j++;
        }
        //printf("%d\n",len);
    }
    return ans;
}
