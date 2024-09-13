/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(const void *pa,const void *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
 int cmp1(const void *pa,const void *pb)
 {
    return *(int *)pb-*(int *)pa;
 }
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int odd [51]={0};
    int eve [51]={0};
    int oddcount=0;
    int  evecount=0;
    for(int i=0;i<numsSize;i++)
    {
        if(i%2)
        {
            odd[oddcount++]=nums[i];
        }
        else
        {
            eve[evecount++]=nums[i];
        }
    }
    qsort(odd,oddcount,sizeof(int),cmp1);
    qsort(eve,evecount,sizeof(int),cmp);
    for(int i=0;i<numsSize;i++)
    {
        if(i%2)
        {
            nums[i]=odd[i/2];
        }
        else
        {
            nums[i]=eve[i/2];
        }
    }
    *returnSize=numsSize;
    return nums;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    for(int i=2;i<numsSize;i+=2){
        int record=nums[i];
        int j;
        for(j=i-2;j>=0;j-=2){
            if(nums[j]>record){
                nums[j+2]=nums[j];
            }
            else
			{
				break;
			}
        }
        nums[j+2]=record;
    }
    for(int i=3;i<numsSize;i+=2){
        int record=nums[i];
        int j;
        for(j=i-2;j>=0;j-=2){
            if(nums[j]<record){
                nums[j+2]=nums[j];
            }
            else{break;}
        }
        nums[j+2]=record;
    }
    *returnSize=numsSize;
    return nums;
}
