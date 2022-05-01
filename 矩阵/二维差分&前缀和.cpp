struct NumMatrix {
    int n, m;
    vector<vector<int>> sums;
 
    NumMatrix(int _n, int _m) {
		n = _n;
		m = _m;
        sums.resize(n + 1, vector<int> (m + 1));        
    }

	void prefix_matrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sums[i + 1][j + 1] += sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
			}
		}
	}

    void diff_insert(int row1, int col1, int row2, int col2, int c) {
        sums[row1][col1] += c;
        sums[row1][col2 + 1] -= c;
        sums[row2 + 1][col1] -= c;
        sums[row2 + 1][col2 + 1] += c;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
};
