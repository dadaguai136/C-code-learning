int maximumProduct(int* nums, int numsSize) {
    int min1=INT_MAX,min2=INT_MAX;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    for(int i=0;i<numsSize;i++)
    {
        int x=nums[i];
        if(x<min1)
        {
            min2=min1;
            min1=x;
        }
        else if(x<min2)
        {
            min2=x;
        }
        if(x>max1)
        {
            max3=max2;
            max2=max1;
            max1=x;
        }
        else if(x>max2)
        {
            max3=max2;
            max2=x;
        }
        else if(x>max3)
        {
            max3=x;
        }
    }
    return fmax(min1*min2*max1,max1*max2*max3);
}



int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int maximumProduct(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    return max(nums[0]*nums[1]*nums[numsSize-1],nums[numsSize-3]*nums[numsSize-2]*nums[numsSize-1]);
}
