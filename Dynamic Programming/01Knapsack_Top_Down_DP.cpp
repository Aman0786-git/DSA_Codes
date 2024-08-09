int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>>t(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)t[i][j] = 0;
            else
            {
                if (wt[i - 1] <= j) {
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }

        }

    }
    return t[n][W];
}