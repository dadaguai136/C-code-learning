

int triangularSum(int* nums, int numsSize){
    int n=numsSize;
    while(n--)
    {
        for(int i=0;i<n;i++)
        {
            nums[i]=(nums[i]+nums[i+1])%10;
        }
    }
    return nums[0];
}
