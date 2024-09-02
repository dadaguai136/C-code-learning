int longestSubarray(int* nums, int numsSize) {
    int i=0;
    int j=-1;
    int zeroCount=0;
    int maxLen=1;
    while(j<numsSize-1)
    {
        j++;
        zeroCount+=!nums[j];
        while(zeroCount>1)
        {
            zeroCount-=!nums[i];
            i++;
        }
        if(j-i+1>maxLen)
        {
            maxLen=j-i+1;
        }
    }
    return maxLen-1;
}
