void moveZeroes(int* nums, int numsSize) {
    int fast=0;
    int slow=0;
  while(fast<numsSize)
  {
    if(nums[fast]!=0)
    {
        nums[slow]=nums[fast];
        ++slow;
    }
    fast++;
  }
  while(slow<numsSize)
  {
    nums[slow++]=0;
  }
}




void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

void moveZeroes(int *nums, int numsSize) {
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right]) {
            swap(nums + left, nums + right);
            left++;
        }
        right++;
    }
}
