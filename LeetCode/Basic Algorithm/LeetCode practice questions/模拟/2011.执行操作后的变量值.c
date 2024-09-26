int finalValueAfterOperations(char** operations, int operationsSize) {
    char res = 0;
    for (int i = 0; i < operationsSize; ++i) {
        if (operations[i][1] == '+') {
            res++;
        } else {
            res--;
        }
    }
    return res;
}





int finalValueAfterOperations(char** operations, int operationsSize) {
    int x=0;
    for(int i=0;i<operationsSize;i++)
    {
        char *op=operations[i];
        if(!strcmp(op,"X++")||!strcmp(op,"++X"))
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    return x;
}
