bool isPalindrome(string &s, int i, int j) {

	while (i <= j) {
		if (s[i] != s[j])return false;
		i++;
		j--;
	}
	return true;
}
int solve(string &s, int i, int j, vector<vector<int>>&t)
{
	if (t[i][j] != -1)return t[i][j];
	if (i >= j)return 0;
	if (isPalindrome(s, i, j))return 0;
	int ans = INT_MAX;
	for (int k = i; k < j; k++) {

		// int tempAns = 1 + solve(s, i, k, t) + solve(s, k + 1, j, t);
		if (isPalindrome(s, i, k)) {
			ans = min(ans, 1 + solve(s, k + 1, j, t));
		}
	}
	return t[i][j] = ans;
}
int palindromicPartition(string str)
{
	// code here
	int n = str.length();
	vector<vector<int>>t(n + 1, vector<int>(n + 1, -1));
	return solve(str, 0, n - 1, t );
}