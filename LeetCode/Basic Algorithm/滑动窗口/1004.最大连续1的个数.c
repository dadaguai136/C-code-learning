int longestOnes(int* nums, int numsSize, int k) {
    int i=0;
    int j=-1;
    int zeroCount=0;
    int maxLen=0;
    while(j<numsSize-1)
    {
        j++;
        zeroCount+=!nums[j];
        while(zeroCount>k)
        {
            zeroCount-=!nums[i];
            i++;
        }
        if(j-i+1>maxLen)
        {
            maxLen=j-i+1;
        }
    }
    return maxLen;
}
