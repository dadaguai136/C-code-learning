void BubbleSort(int *a, int n) //冒泡排序
{
	int i, j;
	int temp;
	for (i = n - 1; i > 0; i--) //比较n-1次
	{
		for (j = 0; j < i; j++) 
		{
			if (a[j] > a[j + 1]) //从小到大排序
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int lastStoneWeight(int* stones, int stonesSize) {
	while (stonesSize > 1) 
	{
		BubbleSort(stones, stonesSize);//初始化排序和每次粉碎石头后再次排序
		stones[stonesSize - 2] = stones[stonesSize - 1] - stones[stonesSize - 2];
		stonesSize--;
	}
	return stones[0];
}
