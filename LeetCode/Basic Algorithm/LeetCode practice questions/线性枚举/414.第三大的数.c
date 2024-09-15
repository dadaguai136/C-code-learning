int thirdMax(int* nums, int numsSize){
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN; // ��ʼ��ǰ�������

	for (int i = 0; i < numsSize; i++) {
		// �����ظ�������
		if (nums[i] == first || nums[i] == second || nums[i] == third) {
			continue;
		}

		// ����ǰ�������
		if (nums[i] > first) {
			third = second; // ���µ�����
			second = first; // ���µڶ���
			first = nums[i]; // ���µ�һ��
		}
		else if (nums[i] > second) {
			third = second; // ���µ�����
			second = nums[i]; // ���µڶ���
		}
		else if (nums[i] > third) {
			third = nums[i]; // ���µ�����
		}
	}

	// �����������û�и��£����������
	return (third == LONG_MIN) ? first : third;
}
