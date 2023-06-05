// Function to multiply two matrices
Matrix* multiplyMatrix(Matrix* m1, Matrix* m2) {
    if(m1->cols != m2->rows) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.\n");
        return NULL;
    }

    Matrix* result = createMatrix(m1->rows, m2->cols);

    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m2->cols; j++) {
            result->data[i][j] = 0;
            for(int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    return result;
}
