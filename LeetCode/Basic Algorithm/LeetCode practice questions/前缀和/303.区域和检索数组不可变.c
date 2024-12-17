


typedef struct {
    int *sums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret=malloc(sizeof(NumArray));
    ret->sums=malloc(sizeof(int)*(numsSize+1));
    ret->sums[0]=0;
    for(int i=0;i<numsSize;i++)
    {
        ret->sums[i+1]=ret->sums[i]+nums[i];
    }
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->sums[right+1]-obj->sums[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->sums);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
