

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) > (b) ? (b) : (a))

#define RETLEN      (10000)

char ret_[RETLEN][RETLEN];
char *ret[RETLEN];


typedef struct {
    int key[2];
    int val;
    UT_hash_handle hh;
}hash_t;

char **printKMoves(int k, int *returnSize) {
    hash_t *pool = (hash_t *)calloc(k, sizeof(hash_t));
    int psize = 0;
    hash_t *head = NULL;
    int cur[2] = {0};
    char dirc = 'R';
    int llen = 0;
    int dlen = 0;
    int rlen = 0;
    int ulen = 0;
    for (int i = 0; i < k; i++) {
        int color;
        hash_t *temp;
        HASH_FIND(hh, head, cur, sizeof(cur), temp);
        if (temp == NULL) {
            hash_t *new = &pool[psize++];
            new->key[0] = cur[0];
            new->key[1] = cur[1];
            new->val = 1;
            HASH_ADD_KEYPTR(hh, head, new->key, sizeof(new->key), new);
            color = 0;
        } else {
            color = temp->val;
            temp->val = (color == 0) ? 1 : 0;
        }
        switch (dirc) {
            case 'L':
                dirc = (color == 0) ? 'U' : 'D';
                break;
            case 'R':
                dirc = (color == 0) ? 'D' : 'U';
                break;
            case 'U':
                dirc = (color == 0) ? 'R' : 'L';
                break;
            case 'D':
                dirc = (color == 0) ? 'L' : 'R';
                break;
            default:
                printf("err\n");
        }

        switch (dirc) {
            case 'L':
                cur[1]--;
                llen = MIN(llen, cur[1]);
                break;
            case 'R':
                cur[1]++;
                rlen = MAX(rlen, cur[1]);
                break;
            case 'U':
                cur[0]++;
                ulen = MAX(ulen, cur[0]);
                break;
            case 'D':
                cur[0]--;
                dlen = MIN(dlen, cur[0]);
                break;
            default:
                printf("err\n");
        }



    }
    int row = ulen - dlen + 1;
    int col = rlen - llen + 1;
    for (int i = 0; i < row; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (col + 1));
        for (int j = 0; j < col; j++) {
            ret[i][j] = '_';
        }
        ret[i][col] = '\0';
    }

    hash_t *te,*tc;
    HASH_ITER(hh, head, te, tc) {
        int y = te->key[0];
        int x = te->key[1];
        y = ulen - y;
        x -= llen;
        ret[y][x] = te->val == 1 ? 'X' : '_';
        // HASH_DEL(head, te);
        // free(te);
    }
    ret[ulen - cur[0]][cur[1] - llen] = dirc;
    *returnSize = row;
    return ret;
}
