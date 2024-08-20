void solve(string ip, string op, vector<string>&ans) {
	//getting the ans when ip lenght is 0
	if (ip.length() == 0) {
		ans.push_back(op);
		return ;
	}
	if (isalpha(ip[0])) {
		string op1 = op;
		string op2 = op;
		op1.push_back(toupper(ip[0]));
		op2.push_back(tolower(ip[0]));
		ip.erase(ip.begin() + 0);
		solve(ip, op1, ans);
		solve(ip, op2, ans);
	}
	else if (isdigit(ip[0])) {
		op.push_back(ip[0]);
		// op2.push_back(ip[0]);
		ip.erase(ip.begin() + 0);
		solve(ip, op, ans);
	}

	return;
}
vector<string> permutation(string s) {
	// Code Here
	string op;
	vector<string>ans;
	solve(s, op, ans);
	return ans;
}
