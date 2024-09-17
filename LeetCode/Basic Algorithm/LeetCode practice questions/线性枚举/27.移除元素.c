int removeElement(int* nums, int numsSize, int val) {
    int l=0;
    int r=numsSize-1;
    while(l<=r)
    {
        if(nums[l]==val)
        {
            int temp;
            temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            r--;
        }
        else
        {
            l++;
        }
    }
    return r+1;
}
