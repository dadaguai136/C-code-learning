/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    int **ans=(int **)malloc(sizeof(int *)*(firstListSize+secondListSize));
    int n=0;
    if(firstListSize==0||secondListSize==0)
    {
        *returnSize=0;
        return ans;
    }
    int p1=0,p2=0;
    int *first=firstList[0][0]<secondList[0][0]?firstList[p1++]:secondList[p2++];
    int a=first[0],b=first[1];
    while(p1<firstListSize||p2<secondListSize)
    {
        int *cur;
        if(firstListSize==p1)
        {
            cur=secondList[p2++];
        }
        else if(secondListSize==p2)
        {
            cur=firstList[p1++];
        }
        else
        {
            cur=firstList[p1][0]<secondList[p2][0]?firstList[p1++]:secondList[p2++];
        }
        int c=cur[0],d=cur[1];
        if(c<=b)
        {
            int *temp=(int *)malloc(sizeof(int)*2);
            temp[0]=c;
            temp[1]=fmin(b,d);
            ans[n++]=temp;
        }
        a=fmin(a,c);
        b=fmax(b,d);
    }
    *returnSize=n;
    *returnColumnSizes=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return ans;
}




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize,
int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes)
{
    int ** returnSection = (int **)malloc(sizeof(int *) *2000);//����һ�����ĳ���

    int a = 0;
    int b = 0;
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int)*2000);
    while(a <firstListSize && b < secondListSize )
    {
        //���ཻ�ģ������Ѿ����� ��
        if(firstListColSize[a] && secondListColSize[b])
        {

            if(  firstList[a][0] <  secondList[b][0])   //first�Ľ���  ����second�Ŀ�ʼ
            {
                //��� 1- 3
                //���1�ж�
                if(firstList[a][1] >= secondList[b][1] )
                {
                    //�ظ��ķ�ΧΪ ����seconde�Ŀռ�
                    returnSection[*returnSize] = (int *)malloc(sizeof(int)* 2 );
                     (*returnColumnSizes)[*returnSize]= 2;
                    returnSection[*returnSize][0] =   secondList[b][0];
                    returnSection[*returnSize][1] =   secondList[b][1];
                    *returnSize =  *returnSize + 1; 
                    b++;
                }
                //���2�ж�
                else if(( firstList[a][1] >= secondList[b][0]))
                {
                    returnSection[*returnSize] = (int *)malloc(sizeof(int)* 2 );
   
                    (*returnColumnSizes)[*returnSize]= 2;
                    returnSection[*returnSize][0] =   secondList[b][0];
                    returnSection[*returnSize][1] =   firstList[a][1];
                    *returnSize =  *returnSize + 1; 
                    a++;
                }
                //���3�����ж���
                else
                {
                    a++;
                }
            }
            else
            {
                //��� 4- 6                    
                //���4�ж�
                if(firstList[a][1] <= secondList[b][1] )
                {
                    //�ظ��ķ�ΧΪ ����first�Ŀռ�
                    returnSection[*returnSize] = (int *)malloc(sizeof(int)* 2 );
                    (*returnColumnSizes)[*returnSize]= 2;
                    returnSection[*returnSize][0] =   firstList[a][0];
                    returnSection[*returnSize][1] =   firstList[a][1];
                    *returnSize =  *returnSize + 1; 
                    a++;
                }
                //���5�ж�
                else if(( firstList[a][0] <= secondList[b][1]))
                {
                    returnSection[*returnSize] = (int *)malloc(sizeof(int)* 2 );
                     (*returnColumnSizes)[*returnSize]= 2;
                    returnSection[*returnSize][0] =   firstList[a][0];
                    returnSection[*returnSize][1] =   secondList[b][1];
                    *returnSize =  *returnSize + 1; 
                    b++;
                }
                //���6�����ж���
                else
                {
                    b++;
                }
            }
        }
    }

    return returnSection;
}
