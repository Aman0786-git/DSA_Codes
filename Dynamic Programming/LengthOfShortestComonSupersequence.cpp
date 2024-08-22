//Shortest Common Supersequence
// return (length of str1+length of str2 -length of LCS)

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

	return m + n - t[n][m];

}