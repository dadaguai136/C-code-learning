bool isGreen(int *a,int idx,int target)
{
    return a[idx]>=target;
}
int searchInsert(int* nums, int numsSize, int target) {
    int l=-1,r=numsSize;
    while(r-l>1)
    {
        int mid=(r+l)/2;
        if(isGreen(nums,mid,target))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
