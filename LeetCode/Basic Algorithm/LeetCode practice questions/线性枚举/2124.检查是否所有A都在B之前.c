bool checkString(char* s) {
    int flag=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='b'&&flag==0)
        {
            flag=1;
        }
        if(flag==1)
        {
            if(s[i]!='b')
            {
                return false;
            }
        }
    }
    return true;
}



bool checkString(char* s) {
    char x=s[0];
    for(int i=1;s[i];i++)
    {
        if(x>s[i])
        {
            return false;
        }
        x=s[i];
    }
    return true;
}
