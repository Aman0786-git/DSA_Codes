const int mod = 1003;
unordered_map<string, int>ump;
int solve(string s, int i, int j, bool isTrue) {
	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");
	if (ump.find(key) != ump.end())return ump[key];
	if (i >= j )
	{	if (isTrue)
			ump[key] = s[i] == 'T';
		else
			ump[key] = s[i] == 'F';
		return ump[key];
	}

	int ans = 0;
	for (int k = i + 1; k < j; k = k + 2) {
		int lT = solve(s, i, k - 1, true);
		int lF = solve(s, i, k - 1, false);
		int rT = solve(s, k + 1, j, true);
		int rF = solve(s, k + 1, j, false);

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
	return ump[key] = ans ;
}

int countWays(int n, string s) {
	// code here
	return solve(s, 0, n - 1, true);
}
