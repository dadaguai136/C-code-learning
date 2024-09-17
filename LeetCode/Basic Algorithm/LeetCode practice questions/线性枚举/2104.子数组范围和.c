long long subArrayRanges(int* nums, int numsSize) {
    long long ans=0;
    for(int i=0;i<numsSize;i++)
    {
        int min=1000000001;
        int max=-1000000001;
        for(int j=i;j<numsSize;j++)
        {
            if(nums[j]>max)
            {
                max=nums[j];
            }
            if(nums[j]<min)
            {
                min=nums[j];
            }
            ans+=max-min;
        }
    }
    return ans;
}
