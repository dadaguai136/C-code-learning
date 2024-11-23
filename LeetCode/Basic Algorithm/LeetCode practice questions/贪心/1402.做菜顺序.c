int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    qsort(satisfaction,satisfactionSize,sizeof(int),compare);
    int i,temp=0;
    for(i=satisfactionSize-1;i>=0;i--)
    {
        temp+=satisfaction[i];
        if(temp<=0)break;
    }
    i++;
    int ans=0;
    for(int j=1;i<satisfactionSize;i++,j++)
    {
        ans+=satisfaction[i]*j;
    }
    return ans;
}



int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    int n = satisfactionSize;
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
            if (j < i) {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j]);
            }
            res = fmax(res, dp[i][j]);
        }
    }
    return res;
}
