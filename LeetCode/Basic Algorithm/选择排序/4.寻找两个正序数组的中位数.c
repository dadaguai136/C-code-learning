void DelectionSort(int *a, int n) //—°‘Ò∑®≈≈–Ú
{
	for (int i = 0; i < n; i++) 
	{
		int minidx = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[minidx] > a[j]) 
			{
				minidx = j;
			}
		}
		int temp;
		temp = a[i];
		a[i] = a[minidx];
		a[minidx] = temp;
	}
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int n = nums1Size + nums2Size;
	int *ret = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < nums1Size; i++) 
	{
		ret[i] = nums1[i];
	}
	for (int i = 0; i < nums2Size; i++) 
	{
		ret[i + nums1Size] = nums2[i];
	}
	DelectionSort(ret, n);
	if (n & 1) 
	{
		return ret[n / 2];
	}
	return (ret[n / 2 - 1] + ret[n / 2]) / 2.0;
}
