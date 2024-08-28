const int mod = 1003;
int solve(string s, int i, int j, bool isTrue, vector<vector<vector<int>>>&t) {

	if (i >= j )
	{	if (isTrue)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}

	if (t[i][j][isTrue] != -1)return t[i][j][isTrue];
	int ans = 0;
	for (int k = i + 1; k < j; k = k + 2) {
		int lT = solve(s, i, k - 1, true, t);
		int lF = solve(s, i, k - 1, false, t);
		int rT = solve(s, k + 1, j, true, t);
		int rF = solve(s, k + 1, j, false, t);

		if (s[k] == '&') {
			if (isTrue)ans = (ans + lT * rT) % mod ;
			else
				ans = (ans + lT * rF + lF * rT + lF * rF) % mod;
		}
		else if (s[k] == '|') {
			if (isTrue)ans = (ans + lT * rT + lF * rT + lT * rF) % mod;
			else
				ans = (ans + lF * rF) % mod ;
		}
		else if (s[k] == '^') {
			if (isTrue)ans = (ans + lT * rF + lF * rT) % mod ;
			else
				ans = (ans + lF * rF + lT * rT) % mod;
		}
	}
	return t[i][j][isTrue] = ans ;
}

int countWays(int n, string s) {
	// code here
	vector<vector<vector<int>>>t(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
	return solve(s, 0, n - 1, true, t);
}