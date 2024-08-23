// Minimum Number of Insertion in String to make it palindrome
// lengthOfString - lengthOFLPS;

int lcs(int n, int m , string str1, string str2) {
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

int longestPalindromeSubseq(string str1, int n) {
	string str2 = str1;
	reverse(str2.begin(), str2.end());
	return lcs(n, n, str1, str2);
}
int minInsertions(string s) {
	int n = s.length();
	int lpsLength = longestPalindromeSubseq(s, n);
	return n - lpsLength;
}