vector<int> findTwoElement(vector<int> A, int n) {
	// code here
	int arr[n + 1] = {0};
	int miss, dub;

	for (int i = 0; i < n; i++)arr[A[i]]++;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0)miss = i;
		else if (arr[i] > 1)dub = i;
	}


	return {dub, miss};
}