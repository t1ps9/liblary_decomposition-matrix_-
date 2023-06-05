#include <lapacke.h>

void svd(Matrix* m, Matrix* U, Matrix* S, Matrix* Vt) {
    // Check if the input matrix is NULL
    if (m == NULL) {
        printf("Error: The input matrix cannot be NULL.\n");
        return;
    }

    // The LAPACK dgesvd function uses column-major order
    double* a = convertToColumnMajorOrder(m);

    // Initialize the superdiagonal matrix and the orthogonal matrices
    double s[m->cols];
    double u[m->rows * m->rows];
    double vt[m->cols * m->cols];

    // Compute the SVD
    LAPACKE_dgesvd(LAPACK_COL_MAJOR, 'A', 'A', m->rows, m->cols, a, m->cols, s, u, m->rows, vt, m->cols);

    // Convert the output back to row-major order and store it in the output matrices
    U = convertToRowMajorOrder(u, m->rows, m->rows);
    S = convertToDiagonalMatrix(s, m->rows, m->cols);
    Vt = convertToRowMajorOrder(vt, m->cols, m->cols);
}
