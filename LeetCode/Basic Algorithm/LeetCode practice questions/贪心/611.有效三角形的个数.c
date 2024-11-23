int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int triangleNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<numsSize;i++)
    {
        int k=i;
        for(int j=i+1;j<numsSize;j++)
        {
            while(k+1<numsSize&&nums[k+1]<nums[i]+nums[j])
            {
                k++;
            }
            ans+=fmax(k-j,0);
        }
    }
    return ans;
}



int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int triangleNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            int left=j+1,right=numsSize-1,k=j;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(nums[mid]<nums[i]+nums[j])
                {
                    k=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            ans+=k-j;
        }
    }
    return ans;
}
