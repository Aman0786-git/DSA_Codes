// Min no. of multiplications

int solve(int arr[], int i, int j, vector<vector<int>>&t) {
    if (i >= j)return 0;
    if (t[i][j] != -1)return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int tempAns = solve(arr, i, k, t) + solve(arr, k + 1, j, t) +
                      (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, tempAns);
    }
    return t[i][j] = ans;
}
int matrixMultiplication(int n, int arr[])
{
    // code here
    vector<vector<int>>t(n + 1, vector<int>(n + 1, -1));
    return solve(arr, 1, n - 1, t);

}