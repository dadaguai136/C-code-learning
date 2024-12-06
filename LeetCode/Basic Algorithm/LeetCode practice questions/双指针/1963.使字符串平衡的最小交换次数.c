int minSwaps(char* s) {
    int stack=0,swap=0,ret=0;
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='[')
        {
            stack++;
        }
        else
        {
            if(stack>0)
            {
                stack--;
            }
            else
            {
                stack++;
                ret++;
            }
        }
    }
    return ret;
}




int minSwaps(char * s){
    int count = 0, res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
    {
        int c = s[i];
        if (c == '[')
            count ++;
        else 
        {
            count --;
            if (count < 0)
            {
                count = 0;
                res ++;
            }
        }
    }
    return (res + 1) / 2;
}
