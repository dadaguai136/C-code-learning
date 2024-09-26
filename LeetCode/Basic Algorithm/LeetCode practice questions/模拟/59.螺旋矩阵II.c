/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int i = 0,j = 0,k = 1;//��ʼλ��
    int row,col;//����ʵʱλ��
    int num = 1;
    
    //��ʼ�����صĽ������Ĵ�С
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //��ʼ�����ؽ������ans
    int** a = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    for(i = 0,k = 1;k <= n/2;++k)//ѭ����������ÿһ�ָ�����ʼλ��
    {
       
        //����
        for(row = i,col = j; col <= j + n -2*k ; ++col)
        {
            a[row][col] = num++;
        }
        //����
        for(col = j+n-2*k+1; row <= i+n-2*k; ++row)
        {
            a[row][col] = num++;
        }
        //����
        for(row = i+n-2*k+1; col >= j+1; --col)
        {
            a[row][col] = num++;
        }//����
        for(col = j; row >= i+1; --row)
        {
            a[row][col] = num++;
        }
        
         
        ++i;
        ++j;

    }
    if(n%2 != 0)
        {
            a[n/2][n/2] = num;
        }
    return a;
}





int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    //��ʼ�����صĽ������Ĵ�С
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //��ʼ�����ؽ������ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    //����ÿ��ѭ������ʼλ��
    int startX = 0;
    int startY = 0;
    //���ö�ά������м�ֵ����nΪ��������Ҫ������м���������
    int mid = n / 2;
    //ѭ��Ȧ��
    int loop = n / 2;
    //ƫ����
    int offset = 1;
    //��ǰҪ��ӵ�Ԫ��
    int count = 1;

    while(loop) {
        int i = startX;
        int j = startY;
        //ģ���ϲ������
        for(; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //ģ���Ҳ���ϵ���
        for(; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //ģ���²���ҵ���
        for(; j > startY; j--) {
            ans[i][j] = count++;
        }
        //ģ�������µ���
        for(; i > startX; i--) {
            ans[i][j] = count++;
        }
        //ƫ��ֵÿ�μ�2
        offset+=2;
        //������ʼλ��ÿ��+1
        startX++;
        startY++;
        loop--;
    }
    //��nΪ������Ҫ�����������м丳ֵ
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}
