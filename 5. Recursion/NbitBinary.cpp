void solve(string op, int ones, int zeros, int size, vector<string>&ans) {
	if (size == 0)
	{
		ans.push_back(op);
		return;
	}

	string op1 = op;
	op1.push_back('1');
	solve(op1, ones + 1, zeros, size - 1, ans);
	if (ones > zeros) {
		string op2;
		op2 = op;
		op2.push_back('0');
		solve(op2, ones, zeros + 1, size - 1, ans);
		return;
	}
}

vector<string> NBitBinary(int n)
{
	// Your code goes here
	vector<string>ans;
	string op = "";
	op.push_back('1');
	int ones = 0, zeros = 0;
	solve(op, ones + 1, zeros, n - 1, ans);
	return ans;
}
