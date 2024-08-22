
int longestCommonSubstr(string str1, string str2) {
    // your code here
    int m = str1.length();
    int n = str2.length();
    int ans = 0;
    vector<vector<int>>t(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)t[i][0] = 0;
    for (int j = 0; j <= n; j++)t[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                ans = max(ans, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return ans;
}