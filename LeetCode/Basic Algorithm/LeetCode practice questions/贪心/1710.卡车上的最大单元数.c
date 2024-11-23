static inline int cmp(const void *pa, const void *pb) {
    return (*(int **)pb)[1] - (*(int **)pa)[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int *), cmp);
    int res = 0;
    for (int i = 0; i < boxTypesSize; i++) {
        int numberOfBoxes = boxTypes[i][0];
        int numberOfUnitsPerBox = boxTypes[i][1];
        if (numberOfBoxes < truckSize) {
            res += numberOfBoxes * numberOfUnitsPerBox;
            truckSize -= numberOfBoxes;
        } else {
            res += truckSize * numberOfUnitsPerBox;
            break;
        }
    }
    return res;
}
