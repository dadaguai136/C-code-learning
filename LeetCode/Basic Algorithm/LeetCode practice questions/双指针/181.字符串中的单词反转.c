char* reverseMessage(char* message) {
    char *stk=(char *)malloc(sizeof(char)*(strlen(message)+1));
    char *ret=(char *)malloc(sizeof(char)*(strlen(message)+1));
    int t=0,count=0,flag;
    for(int i=strlen(message)-1;i>=0;i--)
    {
        if(message[i]!=' ')
        {
            stk[t++]=message[i];
            flag=1;
        }
        else
        {
            if(flag==1)
            {
                while(t>0)
                {
                    ret[count++]=stk[--t];
                }
                ret[count++]=' ';
            }
            flag=0;
        }
    }
    if(t==0)
    {
        if(count>0)
        {
            count--;
        }
    }
    while(t>0)
    {
        ret[count++]=stk[--t];
    }
    ret[count++]=0;
    return ret;
}




int StringLength(const char * string)
{
    for(int i=0;;i++)
    {
        if(string[i] == '\0')
            return i;
    }
}

char * ReversVocabularies(const char * string)
{   

    const int l = StringLength(string);
    if(l==0) return "";
    char * result = (char *)malloc(sizeof(char)*l+1);
    int start=l-1,end=l-1;
    int index = 0;
    while(start>0&&end>0)
    {
        if(string[start]==' ' && string[end]==' ')
        {
            start--;
            end--;
        }
        else
        {
            start--;
        }
        if(string[start]==' ' && string[end]!=' ')
        {
            const int temp = index+(end-start)+1;
            result[index+(end-start)] = ' ';
            for(int i=index+(end-start)-1;i>=index;i--)
            {
                result[i] = string[end];
                end--;
            }
            end=start;
            index=temp;
        }
    }
    int temp = index+(end-start)+1;
    for(int i=index+(end-start);i>=index;i--)
    {
        result[i] = string[end];
        end--;
    }
    while(1)
    {   
        if(temp==0)
            return "";
        if(result[temp-1]!=' ')
            break;
        temp--;
    }
    result[temp--] = '\0';
    return result;
}

char* reverseMessage(char* message) {
    return ReversVocabularies(message);
}
