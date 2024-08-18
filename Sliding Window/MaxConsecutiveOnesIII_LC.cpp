int longestOnes(vector<int>& arr, int k) {
	int i = 0, j = 0, ans = 0;
	int cntZ = 0;
	if (k == arr.size())return k;
	while (j < arr.size()) {
		if (arr[j] == 1)j++;
		else if (arr[j] == 0) {
			cntZ++;
			j++;
		}
		if (cntZ <= k) {
			ans = max(ans, j - i  );
		}
		else if (cntZ > k) {
			while (cntZ > k) {
				if (arr[i] == 0)cntZ--;
				i++;
			}
		}
	}
	return ans;
}