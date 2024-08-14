int countPartitions(int n, int d, vector<int>& arr) {
    // Code here
    const unsigned int mod = 1e9 + 7;
    int sum = 0;
    for (auto it : arr)sum += it;
    if ((d + sum) % 2 != 0)return 0;
    int val = (d + sum) / 2;
    vector<vector<int>>t(n + 1, vector<int>(val + 1, 0));
    t[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= val; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = (t[i - 1][j - arr[i - 1]] % mod + t[i - 1][j] % mod) % mod;
            }
            else
            {
                t[i][j] = t[i - 1][j] % mod;
            }
        }
    }
    return t[n][val];
}