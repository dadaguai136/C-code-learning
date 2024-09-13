int hash[101];
int sumOfUnique(int* nums, int numsSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]++;
    }
    int sum=0;
    for(int j=1;j<=100;j++)
    {
        if(hash[j]==1)
        {
            sum+=j;
        }
    }
    return sum;
}
int hash[101];
int sumOfUnique(int* nums, int numsSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]++;
    }
    int sum=0;
    for(int j=0;j<numsSize;j++)//ÓÅ»¯
    {
        if(hash[nums[j]]==1)
        {
            sum+=nums[j];
        }
    }
    return sum;
}
