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
    /*配置一个空的哈希表,一共三层，一层用来检测行，一层用来检测列，一层用来检测块*/
    int hashTable[3][9][9] = {0};
    int block , i , j , num;
    for(i = 0;i < 9;i++){
        for(j = 0;j < 9;j++){
            if(board[i][j] == '.')
                continue;
            else{
                /*为了匹配hash的数组坐标为0-8，数独里的字符为1-9，此处-1*/
                num = (int)(board[i][j] - '1');
                /*判断是在哪儿一块*/
                block = i / 3 * 3 + j / 3;
                /*判断该数字是否在同一行一列或者一个块中出现过，如果出现过则数独无效*/
                if(hashTable[0][i][num] == 1 || hashTable[1][j][num] == 1 || hashTable[2][block][num] == 1)
                    return false;

                /*如果上述数字没有在行列以及块中出现过，则标记为1，意思出现了1次*/
                hashTable[0][i][num] = 1;
                hashTable[1][j][num] = 1;
                hashTable[2][block][num] = 1;   
            }         
        }
    }
    return true;
}
