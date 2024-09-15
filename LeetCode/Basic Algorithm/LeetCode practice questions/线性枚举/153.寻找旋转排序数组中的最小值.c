int findMin(int* nums, int numsSize) {
    int low=0;
    int high=numsSize-1;
    while(low<high)
    {
        int pivot=(high+low)/2;
        if(nums[pivot]<nums[high])
        {
            high=pivot;
        }
        else
        {
            low=pivot+1;
        }
    }
    return nums[low];
}
