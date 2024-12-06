int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int low = 0, high = numbersSize - 1;
    while (low < high) {
        int sum = numbers[low] + numbers[high];
        if (sum == target) {
            ret[0] = low + 1, ret[1] = high + 1;
            return ret;
        } else if (sum < target) {
            ++low;
        } else {
            --high;
        }
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}
