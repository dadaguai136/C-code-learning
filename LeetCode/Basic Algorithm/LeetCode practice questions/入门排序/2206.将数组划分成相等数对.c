hash[501];
bool divideArray(int* nums, int numsSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]++;
    }
    for(int j=0;j<numsSize;j++)
    {
        if(hash[nums[j]]%2!=0)
        {
            return false;
        }
    }
    return true;
}
