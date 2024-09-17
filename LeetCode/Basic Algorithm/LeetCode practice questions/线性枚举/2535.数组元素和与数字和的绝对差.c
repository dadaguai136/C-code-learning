int differenceOfSum(int* nums, int numsSize) {
    int x=0;
    int y=0;
    for(int i=0;i<numsSize;i++)
    {
        x+=nums[i];
        while(nums[i])
        {
            y+=nums[i]%10;
            nums[i]/=10;
        }
    }
    return abs(x-y);
}
