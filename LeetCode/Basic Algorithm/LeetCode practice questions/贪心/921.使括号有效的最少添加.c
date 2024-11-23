int minAddToMakeValid(char* s) {
    int n=strlen(s);
    int top=0;
    int ans=0;
    char*stk=malloc(sizeof(char)*(n+1));
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            stk[top++]=i;
        }
        else
        {
            if(top>0)
            {
                top--;
            }
            else
            {
                ans++;
            }
        }
    }
    return ans+=top;
}



int minAddToMakeValid(char* s) {
    int n=strlen(s);
    int left=0,right=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            left++;
        }
        else
        {
            if(left>0)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
    }
    right+=left;
    return right;
}
