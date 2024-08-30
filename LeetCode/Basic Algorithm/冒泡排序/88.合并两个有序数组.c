void BubbleSort(int *a, int n) {
	int i, j;
	int temp;
	for (i = n - 1; i > 0; i--) 
	{
		for (j = 0; j < i; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	for (int i = 0; i < nums2Size; i++) 
	{
		nums1[m + i] = nums2[i];
	}
	BubbleSort(nums1, nums1Size);
}
