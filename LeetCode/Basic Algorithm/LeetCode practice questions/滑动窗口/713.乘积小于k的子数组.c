int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int ret = 0;
    int prod = 1, i = 0;
    for (int j = 0; j < numsSize; j++) {
        prod *= nums[j];
        while (i <= j && prod >= k) {
            prod /= nums[i];
            i++;
        }
        ret += j - i + 1;
    }
    return ret;
}




int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if (k == 0) {
        return 0;
    }
    double *logPrefix = (double *)malloc(sizeof(double) * (numsSize + 1));
    for (int i = 0; i < numsSize; i++) {
        logPrefix[i + 1] = logPrefix[i] + log(nums[i]);
    }
    double logk = log(k);
    int ret = 0;
    for (int j = 0; j < numsSize; j++) {
        int l = 0;
        int r = j + 1;
        int idx = j + 1;
        double val = logPrefix[j + 1] - logk + 1e-10;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (logPrefix[mid] > val) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ret += j + 1 - idx;
    }
    free(logPrefix);
    return ret;
}
