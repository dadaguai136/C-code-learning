void sortColors(int* nums, int numsSize) {
for(int i=0;i<numsSize;i++)
{
int mindex=i;//记录下标
for(int j=i+1;j<numsSize;j++)
{
if(nums[mindex]>nums[j])
{
mindex=j;///记录最小数下标
}
}
int temp;
temp=nums[mindex];
nums[mindex]=nums[i];
nums[i]=temp;
}
}
