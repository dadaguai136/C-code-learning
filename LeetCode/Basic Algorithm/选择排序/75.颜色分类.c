void sortColors(int* nums, int numsSize) {
for(int i=0;i<numsSize;i++)
{
int mindex=i;//��¼�±�
for(int j=i+1;j<numsSize;j++)
{
if(nums[mindex]>nums[j])
{
mindex=j;///��¼��С���±�
}
}
int temp;
temp=nums[mindex];
nums[mindex]=nums[i];
nums[i]=temp;
}
}
