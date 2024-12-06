int maximizeWin(int* prizePositions, int prizePositionsSize, int k) {
    int num2=0,sum=0,sum1=0,sum2=0;
    int strat1=0,stop1=0;
    int strat2=0,stop2=0;
    for(;stop1<prizePositionsSize;stop1++)
    {
        while(prizePositions[stop1]-prizePositions[strat1]>k)
        {
            strat1++;
        }
        sum1=stop1-strat1+1;
        for(;prizePositions[stop2]<prizePositions[strat1];stop2++)
        {
            while(prizePositions[stop2]-prizePositions[strat2]>k)
            {
                strat2++;
            }
            num2=stop2-strat2+1;
            if(num2>sum2)
                sum2=num2;
        }
        if(sum1+sum2>sum)
            sum=sum1+sum2;
    }
    printf("%d %d",sum1,sum2);
    return sum;
}




int maximizeWin(int* prizePositions, int prizePositionsSize, int k) {
    int n = prizePositionsSize;
    int *dp = calloc(n + 1, sizeof(int));
    int ans = 0;
    for (int left = 0, right = 0; right < n; right++) {
        while (prizePositions[right] - prizePositions[left] > k) {
            left++;
        }
        ans = fmax(ans, right - left + 1 + dp[left]);
        dp[right + 1] = fmax(dp[right], right - left + 1);
    }
    return ans;
}




int lower_bound(int* arr, int size, int val) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int maximizeWin(int* prizePositions, int prizePositionsSize, int k) {
    int* dp = (int*)calloc(prizePositionsSize + 1, sizeof(int));
    int ans = 0;
    for (int i = 0; i < prizePositionsSize; i++) {
        int x = lower_bound(prizePositions, prizePositionsSize, prizePositions[i] - k);
        ans = fmax(ans, i - x + 1 + dp[x]);
        dp[i + 1] = fmax(dp[i], i - x + 1);
    }
    free(dp);
    return ans;
}
