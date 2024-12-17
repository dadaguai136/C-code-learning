int sumOddLengthSubarrays(int* arr, int arrSize) {
    int sum=0;
    for(int start=0;start<arrSize;start++)
    {
        for(int len=1;start+len<=arrSize;len+=2)
        {
            int end=start+len-1;
            for(int i=start;i<=end;i++)
            {
                sum+=arr[i];
            }
        }
    }
    return sum;
}




#define maxn 101
int sum[maxn];
int sumOddLengthSubarrays(int* arr, int arrSize) {
    sum[0]=arr[0];
    for(int i=1;i<arrSize;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
    int ans=0;
    for(int len=1;len<=arrSize;len+=2)
    {
        for(int l=0;l<arrSize;l++)
        {
            int r=l+len-1;
            if(r>=arrSize)
            {
                break;
            }
            if(l==0)
            {
                ans+=sum[r];
            }
            else
            {
                ans+=sum[r]-sum[l-1];
            }
        }
    }
    return ans;
}





int sumOddLengthSubarrays(int* arr, int arrSize){
    int ans = 0, len = 1;
    while(len <= arrSize){
        int left = 0, right = 0 ,cnt = 0;
        while(right < len){
            cnt += arr[right++];
        }
        ans += cnt;
        while(right < arrSize){
            cnt += arr[right++];
            cnt -= arr[left++];
            ans += cnt;
        }
        len += 2;
    } 
    return ans;
}




int sumOddLengthSubarrays(int* arr, int arrSize) {
    int sum = 0;
    for (int start = 0; start < arrSize; start++) {
        for (int length = 1; start + length <= arrSize; length += 2) {
            int end = start + length - 1;
            for (int i = start; i <= end; i++) {
                sum += arr[i];
            }
        }
    }
    return sum;
}




int sum[101];
int sumOddLengthSubarrays(int* a, int n)
{
    sum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int s=0;
    for(int len=1;len<=n;len+=2)
    {
        for(int l=0;l<n;l++)
        {
            int r=l+len-1;
            if(r>=n)
            {
                break;
            }
            if(l==0)
            {
                s+=sum[r];
            }
            else
            {
                s+=sum[r]-sum[l-1];
            }
        }
    }
    return s;
}
