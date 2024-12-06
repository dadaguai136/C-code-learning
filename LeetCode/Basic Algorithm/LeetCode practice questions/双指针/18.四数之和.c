int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** quadruplets = malloc(sizeof(int*) * 1001);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1001);
    if (numsSize < 4) {
        return quadruplets;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    int length = numsSize;
    for (int i = 0; i < length - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
            continue;
        }
        for (int j = i + 1; j < length - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            int left = j + 1, right = length - 1;
            while (left < right) {
                long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int* tmp = malloc(sizeof(int) * 4);
                    tmp[0] = nums[i], tmp[1] = nums[j], tmp[2] = nums[left], tmp[3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)] = 4;
                    quadruplets[(*returnSize)++] = tmp;
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return quadruplets;
}
