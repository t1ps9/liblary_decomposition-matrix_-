// Function to transpose a matrix
Matrix* transposeMatrix(Matrix* m) {
    Matrix* result = createMatrix(m->cols, m->rows);

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }

    return result;
}
