int pan(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0 && i != nums[i])
            return 0;
    }
    return 1;
}

int nextBeautifulNumber(int n){
    int nums[10];
    for(int i = n + 1; i < 10000000000; i++) {
        memset(nums,0, sizeof(nums));
        int j = i;
        while(j > 0) {
            int k = j % 10;
            nums[k] += 1;
            j /= 10;
        }
        if(pan(nums,10) == 1)
            return i;
    }
    return 0;
}
