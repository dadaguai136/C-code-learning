void BubbleSort(int *a, int n) //ð������
{
	int i, j;
	int temp;
	for (i = n - 1; i > 0; i--) //�Ƚ�n-1��
	{
		for (j = 0; j < i; j++) 
		{
			if (a[j] > a[j + 1]) //��С��������
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
		BubbleSort(stones, stonesSize);//��ʼ�������ÿ�η���ʯͷ���ٴ�����
		stones[stonesSize - 2] = stones[stonesSize - 1] - stones[stonesSize - 2];
		stonesSize--;
	}
	return stones[0];
}
