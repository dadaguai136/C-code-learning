/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes) {
    int arr[8][8]={0};
    arr[king[0]][king[1]]=2;
    for(int i=0;i<queensSize;++i){
        arr[queens[i][0]][queens[i][1]]=1;
    }

    for(int i=0;i<8;++i){
        printf("[");
        for(int j=0;j<8;++j){
            printf("%d ",arr[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
    int count=0;
    for(int i=king[0],j=king[1];j>=0;--j){         //水平方向
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }
     for(int i=king[0],j=king[1];j<8;++j){         //水平方向
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }  
    for(int i=king[0],j=king[1];i>=0;--i){           //垂直方向
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }
    for(int i=king[0],j=king[1];i<8;++i){           //垂直方向
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }

    for(int i=king[0],j=king[1];i>=0&&j>=0;--i,--j){            //对角线
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }
   for(int i=king[0],j=king[1];i<8&&j<8;++i,++j){            //对角线
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }

    for(int i=king[0],j=king[1];i>=0&&j<8;--i,++j){ 
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }
    for(int i=king[0],j=king[1];i<8&&j>=0;++i,--j){ 
        if(arr[i][j]==1){
            arr[i][j]=2;
            ++count;
            break;
        }
    }
    for(int i=0;i<8;++i){
        printf("[");
        for(int j=0;j<8;++j){
            printf("%d ",arr[i][j]);
        }
        printf("]");
        printf("\n");
    }  

    int** ans=(int**)malloc(sizeof(int*)*count);
    *returnColumnSizes=(int*)malloc(sizeof(int)*count);
    for(int i=0;i<count;++i){
        *(ans+i)=(int*)malloc(sizeof(int)*2);
        (*returnColumnSizes)[i]=2;
    }
    int len=0;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(arr[i][j]==2&&(i!=king[0]||j!=king[1])){
                ans[len][0]=i;
                ans[len][1]=j;
                ++len;    
            }
        }
    }
    *returnSize=len;
    return ans;            
}
