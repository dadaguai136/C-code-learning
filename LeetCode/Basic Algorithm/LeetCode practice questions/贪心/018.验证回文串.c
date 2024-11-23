char* filter(char*s)
{
    int len = strlen(s);
    int cnt = 0;
    char*ret = (char*)malloc(sizeof(char) * (len + 1));//±ğºöÊÓÁË'\0'
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            ret[cnt++] = s[i];
        else if(s[i] >= 'a' && s[i] <= 'z')
            ret[cnt++] = s[i] - 32;
        else if(s[i] >= '0' && s[i] <= '9')
            ret[cnt++] = s[i];
    }
    ret[cnt] = '\0';
    return ret;
}

bool isPalindrome(char * s)
{
    char*t = filter(s);
    int len = strlen(t);
    for(int i = 0; i < len / 2; i++)
    {
        if(t[i] != t[len - i - 1])
            return false;
    }   
    return true;
}



