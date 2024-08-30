void InsertSort(int *a, int n) //插入法排序
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)//从1起始循坏
	 {
		temp = a[i];//记录当前数值
		for (j = i - 1; j >= 0; j--) //从当前下标后面遍历
		{
			if (temp < a[j]) 
			{
				a[j + 1] = a[j];//前挪
			} 
			else 
			{
				break;
			}
		}
		a[j + 1] = temp;//换位
	}
}
double trimMean(int* arr, int arrSize) {
	InsertSort(arr, arrSize);
	int cnt = arrSize / 20;
	double ans = 0;
	for (int i = cnt; i < arrSize - cnt; i++) 
	{
		ans += arr[i];
	}
	return ans / (arrSize - 2 * cnt);
}
