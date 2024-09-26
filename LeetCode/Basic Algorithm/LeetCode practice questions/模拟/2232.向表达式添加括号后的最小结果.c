


long getLeftValue(char* expression, int start, int end)
{
    long value = 0;
    for (int i = start; i < end; i++)
    {
        value = value * 10 + expression[i] - '0';
    }
    return value;
}

long getRightValue(char* expression, int start, int end)
{
    long value = 0;
    for (int i = start + 1; i <= end; i++)
    {
        value = value * 10 + expression[i] - '0';
    }
    return value;
}

char* minimizeResult(char* expression)
{
    int len = strlen(expression);
    int indexX = 0;
    for (int i = 0; i < len; i++)
    {
        if (expression[i] == '+')
        {
            indexX = i;
            break;
        }
    }

     //存放到两个字符串中了
    //遍历括号增加的地方了
    long minvalue = INT_MAX;
    int  minLeft  = 0;              //从这里开始滑动
    int  minRight = 0;              //从这里开始滑动
    for (int i = 0; i < indexX ;i++)
    {
        long leftProduct  = getLeftValue(expression,0,i);
        long leftSum      = getLeftValue(expression,i, indexX);
        if (leftProduct == 0)
            leftProduct = 1;

        for (int j = indexX + 1; j < len; j++)
        {
            long RightSum    = getRightValue(expression, indexX,j);
            long RightProduct = getRightValue(expression, j , len-1);

            if (RightProduct == 0)
                RightProduct = 1;

            long temp = leftProduct * RightProduct * (leftSum + RightSum);
            if (temp < minvalue)
            {
                minLeft = i;
                minRight = j;
                minvalue = temp;
            }
        }
    }
    char* newStr = (char*)malloc(sizeof(char) * (len + 3));
    int   newCount = 0;
    int   srcCount = 0;
    
    while (srcCount < len)
    {
        if (srcCount == minLeft)
        {
            newStr[newCount++] = '(';
        }
        else if (srcCount == minRight + 1)
        {
            newStr[newCount++] = ')';
        }
        newStr[newCount++] = expression[srcCount];
        srcCount++;
    }
    if (srcCount == minRight + 1)
    {
        newStr[newCount++] = ')';
    }
    newStr[newCount++] = '\0';
    return newStr;
}
