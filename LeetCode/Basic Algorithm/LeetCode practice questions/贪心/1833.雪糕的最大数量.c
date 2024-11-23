int cmp(int *a, int *b) {
    return *a - *b;
}

int maxIceCream(int *costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), cmp);
    int count = 0;
    int n = costsSize;
    for (int i = 0; i < n; i++) {
        int cost = costs[i];
        if (coins >= cost) {
            coins -= cost;
            count++;
        } else {
            break;
        }
    }
    return count;
}
