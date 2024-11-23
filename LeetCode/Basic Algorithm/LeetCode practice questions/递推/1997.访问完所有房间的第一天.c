int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize) {
    long long dp[nextVisitSize];
    long long sum[nextVisitSize];
    int mod = 1000000007;
    int i;

    dp[0] = 2;
    sum[0] = 0;
    sum[1] = dp[0];
    for (i = 1; i < nextVisitSize - 1; i++) {
        dp[i] = sum[i] - sum[nextVisit[i]] + 2 + mod;
        dp[i] %= mod;
        sum[i + 1] = sum[i] + dp[i];
        sum[i + 1] %= mod;
    }

    return sum[i];
}
