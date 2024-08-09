int f(vector<vector<int>>&t, int W, int wt[], int val[], int n) {
    if (W == 0 || n == 0)return 0;

    if (t[n][W] != -1)return t[n][W];

    else {

        if (wt[n - 1] <= W) {
            return t[n][W] = max(val[n - 1] + f(t, W - wt[n - 1], wt, val, n - 1),
                                 f(t, W, wt, val, n - 1));
        }
        else if (wt[n - 1] > W)
            return t[n][W] = f(t, W, wt, val, n - 1);
    }
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>>t(n + 1, vector<int>(W + 1, -1));
    return f(t, W, wt, val, n);
}