int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    const int MOD = 1e9 + 7;
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) {
        t[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++) {
        t[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % MOD;
            }
            else
                t[i][j] = t[i - 1][j] % MOD ;
        }
    }
    return t[n][sum];
}