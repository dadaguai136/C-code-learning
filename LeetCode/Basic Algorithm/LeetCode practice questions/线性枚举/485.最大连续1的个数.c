int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int flag=0;
    int max=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        {
            flag=flag+1;
            if(flag>max)
            {
                max=flag;
            }
        }
        else
        {
            flag=0;
        }
    }
    return max;
}
