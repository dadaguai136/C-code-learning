int val[26];
int cmp(const void *pa,const void *pb)
{
    return val[*(char *)pa-'a']-val[*(char *)pb-'a'];
}
char* customSortString(char* order, char* s) {
    memset(val,0,sizeof(val));
    for(int i=0;order[i]!='\0';i++)
    {
        val[order[i]-'a']=i+1;
    }
    qsort(s,strlen(s),sizeof(char),cmp);
    return s;
}
