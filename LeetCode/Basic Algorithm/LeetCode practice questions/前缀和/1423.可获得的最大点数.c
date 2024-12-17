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
    // �������ڴ�СΪ n-k
    int windowSize = n - k;
    // ѡǰ n-k ����Ϊ��ʼֵ
    int sum = 0;
    for (int i = 0; i < windowSize; i++) {
        sum += cardPoints[i];
    }
    int ret = sum;
    int minSum = sum;
    for (int i = windowSize; i < n; ++i) {
        // ��������ÿ�����ƶ�һ�����Ӵ��Ҳ���봰�ڵ�Ԫ��ֵ�������ٴ�����뿪���ڵ�Ԫ��ֵ
        sum += cardPoints[i] - cardPoints[i - windowSize];
        minSum = fmin(minSum, sum);
        ret += cardPoints[i];
    }
    return ret - minSum;
}
