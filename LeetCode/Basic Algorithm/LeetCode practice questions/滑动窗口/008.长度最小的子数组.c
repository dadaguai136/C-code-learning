int lower_bound(int *a, int l, int r, int q) {
    if (a[r] < q) return -1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= q) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int minSubArrayLen(int s, int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int *sums = (int *)malloc(sizeof(int) * (numsSize + 1));
    // Ϊ�˷�����㣬�� size = n + 1
    // sums[0] = 0 ��ζ��ǰ 0 ��Ԫ�ص�ǰ׺��Ϊ 0
    // sums[1] = A[0] ǰ 1 ��Ԫ�ص�ǰ׺��Ϊ A[0]
    // �Դ�����
    for (int i = 1; i <= numsSize; i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= numsSize; i++) {
        int target = s + sums[i - 1];
        int bound = lower_bound(sums, 1, numsSize, target);
        if (bound != -1) {
            ans = fmin(ans, bound - (i - 1));
        }
    }
    return ans == INT_MAX ? 0 : ans;
}




int minSubArrayLen(int s, int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        while (sum >= s) {
            ans = fmin(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}
