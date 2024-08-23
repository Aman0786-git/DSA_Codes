//Print Shortest Common Supersequence
//Same as LCS with modification

string SCS(int n, int m, string str1, string str2) {
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
	int i = n, j = m;
	string s = "";
	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			s.push_back(str1[i - 1]);
			i--;
			j--;
		}
		else {
			if (t[i - 1][j] > t[i][j - 1]) {
				s.push_back(str1[i - 1]);
				i--;
			}
			else {
				s.push_back(str2[j - 1]);
				j--;
			}
		}
	}
	while (i > 0) {
		s.push_back(str1[i - 1]);
		i--;
	}
	while (j > 0) {
		s.push_back(str2[j - 1]);
		j--;
	}
	reverse(s.begin(), s.end());
	return s;

}