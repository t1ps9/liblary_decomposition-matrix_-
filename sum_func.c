// Function to add two matrices
Matrix* addMatrix(Matrix* m1, Matrix* m2) {
    if(m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        return NULL;
    }

    Matrix* result = createMatrix(m1->rows, m1->cols);

    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}
