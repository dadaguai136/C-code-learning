int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int Count(int** board, int boardSize, int* boardColSize, int x, int y) {
	int num = 0;
	int rx, ry;
	for (int i = 0; i < 8; i++) {
		rx = x + dx[i];
		ry = y + dy[i];
		if (rx < 0 || rx >= boardSize || ry < 0 || ry >= *boardColSize) {
			continue;
		}
		num = num + (board[rx][ry] & 1);
	}
	return num;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			int num_live = Count(board, boardSize, boardColSize, i, j);
			if ((board[i][j] && num_live == 2) || num_live == 3) {
				board[i][j] |= 2;
			}//将更新后为活细胞的逻辑路径进行合并，简化代码；与2进行按位或运算即将原数据从低到高的第二个比特位取1；
		}
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			board[i][j] >>= 1;
		}
	}
}











/*
    使用额外状态：3代表活细胞更新时死了，4代表死细胞更新时活了；
*/
#define Live 1
#define Dead 0
#define Live_to_Dead 3
#define Dead_to_Live 4

int judge1(int surr, int now) {
    if (now == Dead && surr == 3) {
        return Dead_to_Live;
    }
    if (now == Live) {
        if (surr < 2 || surr > 3) {  // 修正条件
            return Live_to_Dead;
        }
    }
    return now;
}

int judge2(int statu) {
    switch (statu) {
        case Dead_to_Live: return Live;
        case Live_to_Dead: return Dead;
        default: return statu;
    }
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    // 第一遍遍历进行标记（不改变原始状态）
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {
            int surr = 0;  // 当前细胞周围的活细胞数量
            
            // 判断周围八个位置
            for (int k = 0; k < 8; ++k) {
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if (dx >= 0 && dx < boardSize && dy >= 0 && dy < boardColSize[dx]) {
                    if (board[dx][dy] == Live || board[dx][dy] == Live_to_Dead) {
                        surr++;
                    }
                }
            }
            board[i][j] = judge1(surr, board[i][j]);  // 根据邻居数量判断状态
        }
    }

    // 第二遍遍历更新状态
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {
            board[i][j] = judge2(board[i][j]);  // 根据标记更新最终状态
        }
    }
}
