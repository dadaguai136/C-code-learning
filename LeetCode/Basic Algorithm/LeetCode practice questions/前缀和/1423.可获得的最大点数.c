int maxScore(int* cardPoints, int n, int k) {
    int s=0;
    for(int i=0;i<k;i++)
    {
        s+=cardPoints[i];
    }
    int max=s;
    for(int i=1;i<=k;i++)
    {
        s+=cardPoints[n-i]-cardPoints[k-i];
        max=fmax(max,s);
    }
    return max;
}





int maxScore(int* cardPoints, int n, int k) {
    int m=n-k;
    int s=0;
    for(int i=0;i<m;i++)
    {
        s+=cardPoints[i];
    }
    int total=s;
    int ans=s;
    for(int i=m;i<n;i++)
    {
        total+=cardPoints[i];
        s+=cardPoints[i]-cardPoints[i-m];
        ans=fmin(ans,s);
    }
    ans=total-ans;
    return ans;
}





int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int n = cardPointsSize;
    // 滑动窗口大小为 n-k
    int windowSize = n - k;
    // 选前 n-k 个作为初始值
    int sum = 0;
    for (int i = 0; i < windowSize; i++) {
        sum += cardPoints[i];
    }
    int ret = sum;
    int minSum = sum;
    for (int i = windowSize; i < n; ++i) {
        // 滑动窗口每向右移动一格，增加从右侧进入窗口的元素值，并减少从左侧离开窗口的元素值
        sum += cardPoints[i] - cardPoints[i - windowSize];
        minSum = fmin(minSum, sum);
        ret += cardPoints[i];
    }
    return ret - minSum;
}
