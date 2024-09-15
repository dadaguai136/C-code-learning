int thirdMax(int* nums, int numsSize){
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN; // 初始化前三大的数

	for (int i = 0; i < numsSize; i++) {
		// 跳过重复的数字
		if (nums[i] == first || nums[i] == second || nums[i] == third) {
			continue;
		}

		// 更新前三大的数
		if (nums[i] > first) {
			third = second; // 更新第三大
			second = first; // 更新第二大
			first = nums[i]; // 更新第一大
		}
		else if (nums[i] > second) {
			third = second; // 更新第三大
			second = nums[i]; // 更新第二大
		}
		else if (nums[i] > third) {
			third = nums[i]; // 更新第三大
		}
	}

	// 如果第三大数没有更新，返回最大数
	return (third == LONG_MIN) ? first : third;
}
