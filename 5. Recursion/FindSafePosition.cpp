int solve(vector<int>&v, int k, int idx) {
	int n = v.size();
	if (n == 1)return v[0];

	idx = (idx + k) % n;
	v.erase(v.begin() + idx);
	solve(v, k, idx);

}

int safePos(int n, int k) {
	// code here
	vector<int>v(n);
	iota(v.begin(), v.end(), 1);
	return solve(v, k - 1, 0);
}
