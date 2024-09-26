const int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

int rotatedDigits(int n){
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        char num[8];
        sprintf(num, "%d", i);
        bool valid = true, diff = false;
        for (int j = 0; num[j]; j++) {
            if (check[num[j] - '0'] == -1) {
                valid = false;
            }
            else if (check[num[j] - '0'] == 1) {
                diff = true;
            }
        }
        if (valid && diff) {
            ++ans;
        }
    }
    return ans;
}



int isgood(int n)
{
    if(n==3||n==4||n==7)
        return 0;
    else if(n==0||n==1||n==8)
        return 1;
    else
        return 2;
}
int rotatedDigits(int n) {
    int i=1;
    int count=0;
    for(i=0;i<=n;i++)
    {
        int j=i;
        int temp=0;
        int k=1;
        while(j)
        {
            if(isgood(j%10)==2)
                temp++;
            if(isgood(j%10)==0)
            {
                k=0;
                break;
            }  
            j/=10; 
        }
        if(temp&&k)
            count++;
    }
    return count;
}
