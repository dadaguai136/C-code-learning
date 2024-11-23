#define MAX(a,b)((a)>(b)?(a):(b))

int minOperations(int* nums, int numsSize){
    int pre=nums[0]-1,res=0;
    for(int i=0;i<numsSize;i++){
        pre=MAX(pre+1,nums[i]);
        res+=pre-nums[i];
    }
    return res;
}
