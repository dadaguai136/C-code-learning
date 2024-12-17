/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    memset(ans, 0, n * sizeof(int));

    // 使用差分数组
    for (int i = 0; i < bookingsSize; i++) {
        int start = bookings[i][0] - 1;
        int end = bookings[i][1] - 1;
        int seats = bookings[i][2];
        ans[start] += seats;
        if (end + 1 < n) {
            ans[end + 1] -= seats;
        }
    }

    // 计算累加和
    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
    }

    return ans;
}




int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    int* nums = malloc(sizeof(int) * n);
    memset(nums, 0, sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < bookingsSize; i++) {
        nums[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n) {
            nums[bookings[i][1]] -= bookings[i][2];
        }
    }
    for (int i = 1; i < n; i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}
