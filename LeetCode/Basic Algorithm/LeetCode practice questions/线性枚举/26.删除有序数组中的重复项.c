int removeDuplicates(int* nums, int numsSize) {
    int sort[numsSize];
    int n = 0;
    int p1 = 0;
    int tmp = 0;
    while (p1 < numsSize)
    {
        if (p1 == 0)
        {
            tmp = nums[p1++];
        }
        else if (nums[p1] == nums[p1 - 1])
        {
            p1++;
            continue;
        }
        else if (nums[p1] != nums[p1 - 1])
        {
            tmp = nums[p1++];
        }

        sort[n++] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = sort[i];
    }

    return n;
}




int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0)
    {
        return 0;
    }
    int fast=1,slow=1;
    while(fast<numsSize)
    {
        if(nums[fast]!=nums[fast-1])
        {
            nums[slow]=nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}
