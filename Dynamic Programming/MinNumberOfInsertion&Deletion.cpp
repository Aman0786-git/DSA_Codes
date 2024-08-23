//Min number of Insertion and Deletion
// Deletion = length of x - length of LCS
// Insertion = length of y - length of LCS

int minOperations(string x, string y)
{
	// Your code goes here
	int m = x.length();
	int n = y.length();
	vector<vector<int>>t(m + 1, vector<int>(n + 1));
	for (int i = 0; i <= m; i++)t[i][0] = 0;
	for (int j = 0; j <= n; j++)t[0][j] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}

	return  m + n - 2 * t[m][n];

}