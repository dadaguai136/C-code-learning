int removeDuplicates(int* nums, int numsSize) 
{
    int k = 1;
    for(int i = 1;i<numsSize;i++)
    {
        int i32Flag = 0;
        for(int j = 0;j<k;j++)
        {
            if(nums[j] == nums[i])
            {
                i32Flag++;
            }
        }
        if(i32Flag <2 )
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}




int removeDuplicates(int* nums, int numsSize) {
    if(numsSize<=2)
    {
        return numsSize;
    }
    int fast=2,slow=2;
    while(fast<numsSize)
    {
        if(nums[slow-2]!=nums[fast])
        {
            nums[slow]=nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
