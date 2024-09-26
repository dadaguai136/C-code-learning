/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int i = 0,j = 0,k = 1;//起始位置
    int row,col;//行列实时位置
    int num = 1;
    
    //初始化返回的结果数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** a = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    for(i = 0,k = 1;k <= n/2;++k)//循环的轮数，每一轮更新起始位置
    {
       
        //上行
        for(row = i,col = j; col <= j + n -2*k ; ++col)
        {
            a[row][col] = num++;
        }
        //右行
        for(col = j+n-2*k+1; row <= i+n-2*k; ++row)
        {
            a[row][col] = num++;
        }
        //下行
        for(row = i+n-2*k+1; col >= j+1; --col)
        {
            a[row][col] = num++;
        }//左行
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
    //初始化返回的结果数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    //设置每次循环的起始位置
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;
    //循环圈数
    int loop = n / 2;
    //偏移数
    int offset = 1;
    //当前要添加的元素
    int count = 1;

    while(loop) {
        int i = startX;
        int j = startY;
        //模拟上侧从左到右
        for(; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //模拟右侧从上到下
        for(; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //模拟下侧从右到左
        for(; j > startY; j--) {
            ans[i][j] = count++;
        }
        //模拟左侧从下到上
        for(; i > startX; i--) {
            ans[i][j] = count++;
        }
        //偏移值每次加2
        offset+=2;
        //遍历起始位置每次+1
        startX++;
        startY++;
        loop--;
    }
    //若n为奇数需要单独给矩阵中间赋值
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}
