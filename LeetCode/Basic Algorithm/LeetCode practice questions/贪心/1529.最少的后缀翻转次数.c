int minFlips(char* target) {
    bool c=false;
    int ans=0;
    int n=strlen(target);
    for(int i=n-1;i>=0;i--)
    {
        if(target[i]=='1')
        {
            while(i>=0&&target[i]=='1')
            {
                i--;
            }
            ans+=c==false?1:2;
            i+=1;
        }
        else
        {
            while(i>=0&&target[i]=='0')
            {
                i--;
            }
            c=true;
            i+=1;
        }
    }
    return ans;
}



int minFlips(char* target) {
    int sum=target[0]=='1'?1:0;
    for(int i=1;i<strlen(target);i++)
    {
        if(target[i]!=target[i-1])
        {
            sum++;
        }
    }
    return sum;
}
