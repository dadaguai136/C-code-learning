int line[9];
int column[9];
int block[3][3];
bool valid;
int* spaces[81];
int spacesSize;

void flip(int i, int j, int digit) {
    line[i] ^= (1 << digit);
    column[j] ^= (1 << digit);
    block[i / 3][j / 3] ^= (1 << digit);
}

void dfs(char** board, int pos) {
    if (pos == spacesSize) {
        valid = true;
        return;
    }

    int i = spaces[pos][0], j = spaces[pos][1];
    int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
    for (; mask && !valid; mask &= (mask - 1)) {
        int digitMask = mask & (-mask);
        int digit = __builtin_ctz(digitMask);
        flip(i, j, digit);
        board[i][j] = digit + '0' + 1;
        dfs(board, pos + 1);
        flip(i, j, digit);
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    memset(line, 0, sizeof(line));
    memset(column, 0, sizeof(column));
    memset(block, 0, sizeof(block));
    valid = false;
    spacesSize = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int digit = board[i][j] - '0' - 1;
                flip(i, j, digit);
            }
        }
    }

    while (true) {
        int modified = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
                    if (!(mask & (mask - 1))) {
                        int digit = __builtin_ctz(mask);
                        flip(i, j, digit);
                        board[i][j] = digit + '0' + 1;
                        modified = true;
                    }
                }
            }
        }
        if (!modified) {
            break;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                spaces[spacesSize] = malloc(sizeof(int) * 2);
                spaces[spacesSize][0] = i;
                spaces[spacesSize++][1] = j;
            }
        }
    }

    dfs(board, 0);
}
