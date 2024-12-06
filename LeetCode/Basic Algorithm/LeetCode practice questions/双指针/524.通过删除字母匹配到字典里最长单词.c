typedef struct
{
    int index;
    int length;
    char str[1001];
}Arr;
int cmp(const void *pa,const void *pb)
{
    Arr A=*(Arr *)pa;
    Arr B=*(Arr *)pb;
    if(A.length==B.length)
    {
        return strcmp(A.str,B.str);
    }
    return B.length-A.length;
}
int same(char *s,char *word)
{
    while(*word)
    {
        s=strchr(s,*word);
        if(!s)
        {
            return 0;
        }
        s++;
        word++;
    }
    return 1;
}
char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    Arr ret[1001];
    int size=0;
    for(int i=0;i<dictionarySize;i++)
    {
        if(same(s,dictionary[i]))
        {
            strcpy(ret[size].str,dictionary[i]);
            ret[size].index=i;
            ret[size].length=strlen(dictionary[i]);
            size++;
        }
    }
    qsort(ret,size,sizeof(Arr),cmp);
    if(size>0)
    {
        return dictionary[ret[0].index];
    }
    return "";
}




char* findLongestWord(char* s, char** d, int dSize) {
    int maxLength=0;
    char *dd;
    char *p="";
    for(int i=0;i<dSize;i++)
    {
        dd=d[i];
        int j=0,k=0;
        while(s[j]&&dd[k])
        {
            if(s[j]==dd[k])
            {
                k++;
            }
            j++;
        }
        if(dd[k]!='\0')
        {
            continue;
        }
        else
        {
            if(k>maxLength)
            {
                maxLength=k;
                p=d[i];
            } 
            else if(k==maxLength)
            {
                if(strcmp(d[i],p)<0)
                {
                    p=d[i];
                }
            }
            else
            {
                continue;
            }
        }
    }
    return p;
}




char * findLongestWord(char * s, char ** d, int dSize){
    char *LongestWord = "",*p = s,*q;
    int i,j,k,longest_length = -1; 
    for(i=0 ; i<dSize; i++){//相当于在d中寻找s的子串
        q = d[i];
        j = k = 0;//注意初始化0得放在for里头，不然第一次匹配过后j、k的值就会固定了
        while(p[j]!='\0' && q[k]!='\0'){
            if(p[j] == q[k])
                k++;
            j++;
        }
        if(q[k] != '\0')//如果d中的一个子串没走到末尾，则该子串不匹配
            continue;
        else{
            if(k > longest_length){//遇到匹配长度更长的就更新结果
                longest_length = k;
                LongestWord = q;
            }
            else 
                if(k == longest_length){//遇到相等的子串就比较大小
                    if(strcmp(q,LongestWord) < 0){
                        longest_length = k;
                        LongestWord = q;
                    }
                }
                else
                    continue;
        }
    }
    return LongestWord;
}
