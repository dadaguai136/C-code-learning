int hash[2001];
int findFinalValue(int* nums, int numsSize, int original) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]=1;
    }
    while(1)
    {
        if(hash[original]==1)
        {
            original*=2;
        }
        else
        {
            break;
        }
    }
    return original;
}
