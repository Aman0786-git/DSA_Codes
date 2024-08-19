//Coin Change(No Of Ways) gfg
long long int count(int coins[], int n, int amount) {

	// code here.

	vector<vector<long long int>>t(n + 1, vector<long long int>(amount + 1));

	for (int i = 0; i <= n; i++)t[i][0] = 1;
	for (int j = 1; j <= amount; j++)t[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= amount; j++) {
			if (coins[i - 1] <= j)
				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][amount];
}