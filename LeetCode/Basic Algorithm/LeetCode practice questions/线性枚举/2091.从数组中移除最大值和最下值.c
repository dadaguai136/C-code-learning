int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int minimumDeletions(int* nums, int numsSize) {
    int minIdx=0,maxIdx=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<nums[minIdx])
        {
            minIdx=i;
        }
        if(nums[i]>nums[maxIdx])
        {
            maxIdx=i;
        }
    }
    int ans=0;
    ans=numsSize-(max(maxIdx,minIdx)-min(maxIdx,minIdx)-1);
    ans=min(ans,max(maxIdx,minIdx)+1);
    ans=min(ans,numsSize-min(maxIdx,minIdx));
    return ans;
}
