#define maxn 101
int sum[maxn];
int largestAltitude(int* gain, int gainSize) {
    sum[0]=gain[0];
    int max=sum[0];
    for(int i=1;i<gainSize;i++)
    {
        sum[i]=sum[i-1]+gain[i];
        if(max<sum[i])
        {
            max=sum[i];
        }
    }
    if(max<0)
    {
        max=0;
    }
    return max;
}




#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestAltitude(int* gain, int gainSize){
     int ans = 0, sum = 0;
    for (int i = 0; i < gainSize; i++) {
        sum += gain[i];
        ans = MAX(ans, sum);
    }
    return ans;
}
