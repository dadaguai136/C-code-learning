int* getMaximumXor(int* nums, int n, int maximumBit, int* returnSize) {
    *returnSize=n;
    int* ans;
    int* tool;
    ans=(int*)malloc(n*sizeof(int));
    tool=(int*)malloc(n*sizeof(int));
    tool[0]=nums[0]; 
    for(int j=1;j<n;j++){
        tool[j]=tool[j-1]^nums[j];
    }
    for(int i=0;i<n;i++){
        ans[n-i-1]=((1<<maximumBit)-1)^tool[i];
    }
    return ans;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize){
//面向案例编程，发现异或完的结果都是等于2^maximumbit-1
    int *ans=(int*)malloc(sizeof(int)*numsSize);
    int comp=pow(2,maximumBit)-1;
    int temp=0;
    for(int i=0;i<numsSize;i++){
        temp^=nums[i];
        ans[numsSize-i-1]=temp^comp;
    }
    *returnSize=numsSize;
    return ans;
}
