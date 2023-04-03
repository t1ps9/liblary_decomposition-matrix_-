int determinant(int matrix[][N], int n) {
    int det = 0;
    int submatrix[N][N];
    
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        for (int k = 0; k < n; k++) {
            int i = 0, j = 0;
            
            for (int row = 1; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (col == k) {
                        continue;
                    }
                    submatrix[i][j++] = matrix[row][col];
                    if (j == n - 1) {
                        i++;
                        j = 0;
                    }
                }
            }
            det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * determinant(submatrix, n - 1);
        }
    }
    
    return det;
}
