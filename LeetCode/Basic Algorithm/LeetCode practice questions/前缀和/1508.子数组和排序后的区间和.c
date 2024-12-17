int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int newsize = numsSize * (numsSize + 1) / 2;
    int* newArray = (int*)malloc(newsize * sizeof(int));
    int count = 0;
    for(int i = 0; i < numsSize; i ++){
        int sum = 0;
        for(int j = i; j < numsSize; j ++){
            sum += nums[j];
            newArray[count++] = sum;
        }
    }
    qsort(newArray, (numsSize * (numsSize + 1) / 2), sizeof(int), compare);
    int sum = 0;
    for(int i = left-1; i < right; i++){
        sum += newArray[i];
        sum %= 1000000007;
    }
    return sum;
}





const int mod=1e9+7;
int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int getSum(int *nums,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=nums[i];   
    }
    return sum;
}
int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int ret[n*(n+1)/2];
    int k=0;
    for(int i=1;i<=numsSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            ret[k++]=getSum(&nums[j],i-j);
        }
    }
    qsort(ret,k,sizeof(int),cmp);
    long long ans=0;
    for(int i=left-1;i<right;i++)
    {
        ans+=ret[i];
    }
    int answer=(int)(ans%mod);
    return answer;
}
