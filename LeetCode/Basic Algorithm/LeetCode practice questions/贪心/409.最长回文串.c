int longestPalindrome(char * s)
{
    int c[128]={0},ret=0;
    
    for(int i=0;i<strlen(s);i++)
    {
        c[s[i]]++;
    }

    for(int i=0;i<128;i++)
    {
        ret+=c[i]-c[i]%2;
    }


    return ret+(ret!=strlen(s));
}



int longestPalindrome(char* s) {
    int alphabet[2][26] = {{0,0},};
    char* p = s;
    int len = 0, odd = 0;

    memset(alphabet,0,26*2*sizeof(int));
    while(*p)
    {
        if( (*p >= 'a') && (*p <= 'z') )
        {
            alphabet[0][*p - 'a']++;
        }
        else if((*p >= 'A') && (*p <= 'Z'))
        {
            alphabet[1][*p - 'A']++;
        }
        p++;
    }

    for(int i = 0;i < 26;i++)
    {
        if(alphabet[0][i] % 2)
        {
            len += alphabet[0][i] - 1;
            odd = 1;
        }
        else 
        {
            len += alphabet[0][i];
        }
        if(alphabet[1][i] % 2)
        {
            len += alphabet[1][i] - 1;
            odd = 1;
        }
        else 
        {
            len += alphabet[1][i];
        }
    }

    return len + odd;

}



