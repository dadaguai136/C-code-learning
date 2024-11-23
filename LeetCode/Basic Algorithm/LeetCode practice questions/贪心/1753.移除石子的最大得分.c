#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumScore(int a, int b, int c) {
    int sum = a + b + c;
    int maxVal = MAX(a, MAX(b, c));
    return MIN(sum - maxVal, sum / 2);
}
