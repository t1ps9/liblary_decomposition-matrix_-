// Function to calculate the determinant of a matrix
int determinant(Matrix* m) {
    if (m->rows != m->cols) {
        printf("Error: The determinant is only defined for square matrices.\n");
        return 0;
    }

    if (m->rows == 1) {
        return m->data[0][0];
    } else if (m->rows == 2) {
        return m->data[0][0]*m->data[1][1] - m->data[0][1]*m->data[1][0];
    }

    int det = 0;
    for(int i = 0; i < m->rows; i++) {
        Matrix* submatrix = createMatrix(m->rows-1, m->cols-1);

        for(int j = 1; j < m->rows; j++) {
            int offset = 0;
            for(int k = 0; k < m->cols; k++) {
                if(k == i) {
                    offset = 1;
                    continue;
                }
                submatrix->data[j-1][k-offset] = m->data[j][k];
            }
        }

        det += (i % 2 ? -1 : 1) * m->data[0][i] * determinant(submatrix);
        freeMatrix(submatrix);
    }

    return det;
}
