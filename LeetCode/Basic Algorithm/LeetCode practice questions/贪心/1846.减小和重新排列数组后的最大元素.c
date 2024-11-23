int maximumElementAfterDecrementingAndRearranging(int *arr, int arrSize) {
    int cnt[arrSize + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < arrSize; i++) {
        cnt[(int)fmin(arr[i], arrSize)]++;
    }
    int miss = 0;
    for (int i = 1; i <= arrSize; ++i) {
        if (cnt[i] == 0) {
            ++miss;
        } else {
            miss -= fmin(cnt[i] - 1, miss);  // miss 不会小于 0，故至多减去 miss 个元素
        }
    }
    return arrSize - miss;
}



int cmp(int *a, int *b) {
    return *a - *b;
}

int maximumElementAfterDecrementingAndRearranging(int *arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    arr[0] = 1;
    for (int i = 1; i < arrSize; ++i) {
        arr[i] = fmin(arr[i], arr[i - 1] + 1);
    }
    return arr[arrSize - 1];
}
