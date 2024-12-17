/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* statisticalResult(int* arrayA, int arrayASize, int* returnSize){
    *returnSize=arrayASize;
    int* ans=malloc(sizeof(int)*arrayASize);
    int s=1,flag=0;
    for(int i=0; i<arrayASize; i++){
        if(arrayA[i]) s*=arrayA[i];
        else flag++;
    }
    for(int i=0; i<arrayASize; i++){
        if(flag==1){
            if(arrayA[i]) ans[i]=0;
            else ans[i]=s;
        }else if(flag>1) ans[i]=0;
        else ans[i]=s/arrayA[i];
    }
    return ans;
}




int* statisticalResult(int* arrayA, int arrayASize, int* returnSize) {
    int p = 1, i0 = -1; * returnSize = arrayASize;
    for (int i = 0; i < arrayASize; ++ i) 
        if (arrayA[i]) p *= arrayA[i];
        else {
            if (i0 >= 0) { 
                memset(arrayA, 0, sizeof(int) * arrayASize);
                return arrayA;
            }
            i0 = i;
        }
    if (i0 != -1) {
        memset(arrayA, 0, sizeof(int) * arrayASize);
        arrayA[i0] = p;
        return arrayA;
    }
    for (int j = 0; j < arrayASize; ++ j) arrayA[j] = p / arrayA[j];
    return arrayA;
}
