int minSubsetDiff(int arr[], int range, int n) {

	bool t[n + 1][range + 1];
	for (int i = 0; i <= n; i++) {
		t[i][0] = true;
	}

	for (int j = 1; j <= range; j++) {
		t[0][j] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= range; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	int ans;
	for (int j = range / 2; j >=  0; j--) {
		if (t[n][j] == true)
		{
			ans = range - 2 * j;
			break;
		}
	}
	return ans;
}

int minDifference(int arr[], int n)  {

	// Your code goes here
	int range = 0;
	for (int i = 0; i < n; i++)range += arr[i];
	return minSubsetDiff(arr, range, n);
}
