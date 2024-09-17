int getNum(char *row)
{
    int sum=0,len=strlen(row);
    for(int i=0;i<len;i++)
    {
        sum+=(row[i]-'0');
    }
    return sum;
}
int numberOfBeams(char** bank, int bankSize) {
    int res=0,lastCnt=0;
    for(int i=0;i<bankSize;i++)
    {
        int cnt=getNum(bank[i]);
        if(cnt!=0)
        {
            res+=lastCnt*cnt;
            lastCnt=cnt;
        }
    }
    return res;
}
