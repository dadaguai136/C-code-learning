int longestSemiRepetitiveSubstring(char * s){
    int i=0;
    int j=-1;
    int len=strlen(s);
    int sameCnt=0;
    int maxLen=0;
    while(j<len-1)
    {
        j++;
        if(j-i>0)
        {
            if(s[j-1]==s[j])
            {
                ++sameCnt;
            }
            while(sameCnt>1)
            {
                if(s[i]==s[i+1])
                {
                    --sameCnt;
                }
                i++;
            }
        }
        if(j-i+1>maxLen)
        {
            maxLen=j-i+1;
        }
    }
    return maxLen;
}
