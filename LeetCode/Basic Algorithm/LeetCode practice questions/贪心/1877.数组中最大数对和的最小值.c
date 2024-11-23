int cmp(int *a, int *b) {
    return *a - *b;
}

int minPairSum(int *nums, int numsSize) {
    int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize / 2; ++i) {
        res = fmax(res, nums[i] + nums[numsSize - 1 - i]);
    }
    return res;
}
