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
			}//�����º�Ϊ��ϸ�����߼�·�����кϲ����򻯴��룻��2���а�λ�����㼴��ԭ���ݴӵ͵��ߵĵڶ�������λȡ1��
		}
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			board[i][j] >>= 1;
		}
	}
}











/*
    ʹ�ö���״̬��3�����ϸ������ʱ���ˣ�4������ϸ������ʱ���ˣ�
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
        if (surr < 2 || surr > 3) {  // ��������
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
    
    // ��һ��������б�ǣ����ı�ԭʼ״̬��
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {
            int surr = 0;  // ��ǰϸ����Χ�Ļ�ϸ������
            
            // �ж���Χ�˸�λ��
            for (int k = 0; k < 8; ++k) {
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if (dx >= 0 && dx < boardSize && dy >= 0 && dy < boardColSize[dx]) {
                    if (board[dx][dy] == Live || board[dx][dy] == Live_to_Dead) {
                        surr++;
                    }
                }
            }
            board[i][j] = judge1(surr, board[i][j]);  // �����ھ������ж�״̬
        }
    }

    // �ڶ����������״̬
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {
            board[i][j] = judge2(board[i][j]);  // ���ݱ�Ǹ�������״̬
        }
    }
}
