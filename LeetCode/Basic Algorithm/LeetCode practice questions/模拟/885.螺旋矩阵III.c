/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    int** order = (int**) malloc(sizeof(int*) * total);
    *returnColumnSizes = (int*) malloc(sizeof(int) * total);
    *returnSize = total;
    for (int i = 0; i < total; i++) {
        order[i] = (int*) malloc(sizeof(int*) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    int top = rStart, bottom = rStart, left = cStart, right = cStart;
    int index = 0;
    while (index < total) {
        int start1 = fmax(left, 0), end1 = fmin(right, cols - 1);
        for (int col = start1; col <= end1 && top >= 0 && index < total; col++) {
            order[index][0] = top;
            order[index][1] = col;
            index++;
        }
        right++;
        int start2 = fmax(top, 0), end2 = fmin(bottom, rows - 1);
        for (int row = start2; row <= end2 && right < cols && index < total; row++) {
            order[index][0] = row;
            order[index][1] = right;
            index++;
        }
        bottom++;
        int start3 = fmin(right, cols - 1), end3 = fmax(left, 0);
        for (int col = start3; col >= end3 && bottom < rows && index < total; col--) {
            order[index][0] = bottom;
            order[index][1] = col;
            index++;
        }
        left--;
        int start4 = fmin(bottom, rows - 1), end4 = fmax(top, 0);
        for (int row = start4; row >= end4 && left >= 0 && index < total; row--) {
            order[index][0] = row;
            order[index][1] = left;
            index++;
        }
        top--;
    }
    return order;
}
