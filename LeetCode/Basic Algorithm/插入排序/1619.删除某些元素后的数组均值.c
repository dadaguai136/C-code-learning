void InsertSort(int *a, int n) //���뷨����
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)//��1��ʼѭ��
	 {
		temp = a[i];//��¼��ǰ��ֵ
		for (j = i - 1; j >= 0; j--) //�ӵ�ǰ�±�������
		{
			if (temp < a[j]) 
			{
				a[j + 1] = a[j];//ǰŲ
			} 
			else 
			{
				break;
			}
		}
		a[j + 1] = temp;//��λ
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
