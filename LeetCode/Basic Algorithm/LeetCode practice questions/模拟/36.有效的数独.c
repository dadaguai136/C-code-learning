bool isValidSudoku(char** board, int boardSize, int* boardColSize) 
{
    bool hang[9][9] = {false};
    bool lie[9][9] = {false};
    bool gezi[9][9] = {false};

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {
                int nums = board[i][j] - '1';
                int gezidanyuan = (i / 3) * 3 + (j / 3);

                if(hang[i][nums]||lie[j][nums]||gezi[gezidanyuan][nums])
                {
                    return false;
                }

                hang[i][nums] = true;
                lie[j][nums] = true;
                gezi[gezidanyuan][nums] = true;
            }
        }
    }
    return true;
}






bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    /*����һ���յĹ�ϣ��,һ�����㣬һ����������У�һ����������У�һ����������*/
    int hashTable[3][9][9] = {0};
    int block , i , j , num;
    for(i = 0;i < 9;i++){
        for(j = 0;j < 9;j++){
            if(board[i][j] == '.')
                continue;
            else{
                /*Ϊ��ƥ��hash����������Ϊ0-8����������ַ�Ϊ1-9���˴�-1*/
                num = (int)(board[i][j] - '1');
                /*�ж������Ķ�һ��*/
                block = i / 3 * 3 + j / 3;
                /*�жϸ������Ƿ���ͬһ��һ�л���һ�����г��ֹ���������ֹ���������Ч*/
                if(hashTable[0][i][num] == 1 || hashTable[1][j][num] == 1 || hashTable[2][block][num] == 1)
                    return false;

                /*�����������û���������Լ����г��ֹ�������Ϊ1����˼������1��*/
                hashTable[0][i][num] = 1;
                hashTable[1][j][num] = 1;
                hashTable[2][block][num] = 1;   
            }         
        }
    }
    return true;
}
