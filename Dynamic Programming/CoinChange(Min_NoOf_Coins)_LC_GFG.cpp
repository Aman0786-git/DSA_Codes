//Using Recursion

int solve(vector<int>&coins, int sum, int n) {
	if (sum == 0)return 0;
	if (n == 0)return INT_MAX - 1;
	if (coins[n - 1] <= sum) {
		return min(1 + solve(coins, sum - coins[n - 1], n), solve(coins, sum, n - 1));
	}
	else
		return solve(coins, sum, n - 1);
}


//Using Memorization
int solve(vector<int>&coins, int sum, int n, vector<vector<int>>&t) {


	if (sum == 0)return 0;
	if (n == 0)return INT_MAX - 1;
	if (t[n][sum] != -1)return t[n][sum];
	if (coins[n - 1] <= sum) {
		return t[n][sum] = min(1 + solve(coins, sum - coins[n - 1], n, t), solve(coins, sum, n - 1, t));
	}
	else
		return t[n][sum] = solve(coins, sum, n - 1, t);
}
/* main fun for rec. and memo.
	main(){
	int n = 3;
	int sum = 30;
	vector<int>coins = {25, 10, 5};
	vector<vector<int>>t(n + 1, vector<int>(sum + 1, -1));
	//for rec
	int ans = solve(coins, sum, n);
	//for Memo
	int ans = solve(coins, sum, n,t);

	cout<<ans == INT_MAX - 1 ? -1 : ans;
	}
*/

// Top-Down Dp
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<vector<int>>t(n + 1, vector<int>(amount + 1));
	t[0][0];
	for (int i = 1; i <= n; i++)t[i][0] = 0;
	for (int j = 1; j <= amount; j++)t[0][j] = INT_MAX - 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= amount; j++) {
			if (coins[i - 1] <= j)
				t[i][j] = min(t[i][j - coins[i - 1]] + 1, t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	int ans = t[n][amount] == INT_MAX - 1 ? -1 : t[n][amount];
	return ans;
}

