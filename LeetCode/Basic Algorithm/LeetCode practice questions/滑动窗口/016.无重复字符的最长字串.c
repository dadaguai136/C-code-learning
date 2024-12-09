int lengthOfLongestSubstring(char *s)
{
    int res=0;
    int hash[500];
    memset(hash,0,sizeof(hash));
    int len=strlen(s);
    if(len==0) return 0;
    for(int i=0,j=0;j<len;j++)
    {
        hash[s[j]]++;
        if(hash[s[j]]==2)
        {
            res=fmax(res,j-i);
            while(hash[s[j]]!=1)
            {
                hash[s[i]]--;
                i++;
            }
        }
        res=fmax(res,j-i+1);
    }
    return res;
}




int lengthOfLongestSubstring(char * s){
    int map[128] = {0};
    memset(map,-1,sizeof(int)*128);
    int left = -1;//记录不可能重复的左侧边界。为什么是-1，因为如果只有一个字符。应该是0-(-1)应该是1
    int max = 0;//记录最大的不重复子串的长度。
    for(int i = 0; s[i]!='\0';i++){//遍历字符串。
        if(map[s[i]]  == -1){//这个字符没有出现过。
            map[s[i]] = i;
        }else{ //出现过，更新left
            left = left < map[s[i]]?map[s[i]]:left;
            map[s[i]] = i;//更新这个字符出现的新位置
        }
        int len = i - left;
        max = max<len?len:max;
    }
    return max;
}
