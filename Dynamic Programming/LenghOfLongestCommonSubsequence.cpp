/*
    //Memorization: Bottom-up

int solve(int n, int m, string str1, string str2, vector<vector<int>>&t) {
    if (n == 0 || m == 0)return 0;
    if (t[n][m] != -1)return t[n][m];

    if (str1[n - 1] == str2[m - 1])
        return t[n][m] = 1 + solve(n - 1, m - 1, str1, str2, t);
    else
        return t[n][m] = max(solve(n - 1, m, str1, str2, t), solve(n, m - 1, str1, str2, t));
}

int lcs(int n, int m, string str1, string str2) {
    // your code here
    vector<vector<int>>t(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, str1, str2, t);

}
*/


//-TopDown DP-//
int lcs(int n, int m, string str1, string str2) {
    // your code here
    vector<vector<int>>t(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)t[i][0] = 0;
    for (int j = 0; j <= m; j++)t[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }
    return t[n][m];
}