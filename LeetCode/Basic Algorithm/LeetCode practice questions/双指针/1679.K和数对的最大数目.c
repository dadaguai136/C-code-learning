int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int maxOperations(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int l=0,r=numsSize-1;
    int count=0;
    while(l<r)
    {
        if(nums[l]+nums[r]==k)
        {
            count++;
            l++;
            r--;
        }
        else if(nums[l]+nums[r]<k)
        {
            l++;
        }
        else 
        {
            r--;
        }
    }  
    return count;
}




int maxOperations(int* nums, int numsSize, int k){
    int hash[100007]={0};
    int count=0;

    for(int i=0;i<numsSize;i++)
        if(nums[i]<k)
            hash[nums[i]%100007]++;

    for(int i=0;i<numsSize;i++){
        if(nums[i]>=k)
            continue;
        if(hash[(k-nums[i])%100007]>0){
            hash[nums[i]%100007]--;
            hash[(k-nums[i])%100007]--;
            if(hash[nums[i]%100007]>=0)
                count++;
        }
    }

    return count;
}
