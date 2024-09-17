

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_WIDTH 100
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int lines=1;
    int width=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int need=widths[s[i]-'a'];
        width+=need;
        if(width>MAX_WIDTH)
        {
            lines++;
            width=need;
        }
    }
    int *ans=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    ans[0]=lines;
    ans[1]=width;
    return ans;
}






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    *returnSize = 2;
    int n = widthsSize;
    int sum = 0;
    int* ret = (int*)malloc(sizeof(int) * 2);
    //if(!ret) return NULL;
    ret[0] = 1, ret[1] = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((widths[s[i] - 'a']) <= (100 - sum)) {
            sum += widths[s[i] - 'a'];
        }else{
            sum = widths[s[i] - 'a'];
            ret[0] ++;
        }
    }
    ret[1] = sum;
    return ret;
}
