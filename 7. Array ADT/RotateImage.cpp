void firstSwap(vector<vector<int>>& matrix, int i, int j, int n) {
	int temp = matrix[j][i];
	matrix[j][i] = matrix[j][n - 1 - i];
	matrix[j][n - 1 - i] = temp;
	return;
}

void swap(vector<vector<int>>& matrix, int i, int j) {
	int temp = matrix[i][j];
	matrix[i][j] = matrix[j][i];
	matrix[j][i] = temp;
	return;
}


void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j)swap(matrix, i, j);
		}

	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			firstSwap(matrix, i, j, n);
		}

	}

}
