void transpose(int matrix[][MAX], int rows, int cols) {
    int i, j, temp;
    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < cols; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
