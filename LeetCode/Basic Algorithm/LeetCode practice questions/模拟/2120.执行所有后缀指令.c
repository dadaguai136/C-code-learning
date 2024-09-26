/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int* returnSize) {
    int *res=(int *)malloc(sizeof(int)*strlen(s));
    *returnSize=0;
    for(int i=0;i<strlen(s);i++)
    {
        int cnt=0,x=startPos[1],y=startPos[0];
        for(int j=i;j<strlen(s);j++)
        {
            switch(s[j])
            {
                case 'L':x--;break;
                case 'R':x++;break;
                case 'U':y--;break;
                case 'D':y++;break;
            }
            if(x<0||x>=n||y<0||y>=n)
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
        res[(*returnSize)++]=cnt;
    }
    return res;
}
