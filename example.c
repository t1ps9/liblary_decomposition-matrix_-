#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// include the matrix library header here...

int main() {
    srand(time(NULL));

    // Create a 3x3 matrix
    Matrix* m = createMatrix(3, 3);
    printf("Original matrix:\n");
    printMatrix(m);

    // Transpose the matrix
    Matrix* t = transposeMatrix(m);
    printf("\nTransposed matrix:\n");
    printMatrix(t);

    // Create another 3x3 matrix
    Matrix* n = createMatrix(3, 3);
    printf("\nAnother matrix:\n");
    printMatrix(n);

    // Add the two matrices
    Matrix* a = addMatrix(m, n);
    printf("\nSum of matrices:\n");
    printMatrix(a);

    // Subtract the two matrices
    Matrix* s = subtractMatrix(m, n);
    printf("\nDifference of matrices:\n");
    printMatrix(s);

    // Multiply the two matrices
    Matrix* mult = multiplyMatrix(m, n);
    printf("\nProduct of matrices:\n");
    printMatrix(mult);

    // Calculate the determinant of the original matrix
    int det = determinant(m);
    printf("\nDeterminant of the original matrix: %d\n", det);

    // Calculate the rank of the original matrix
    int rank = rankMatrix(m);
    printf("\nRank of the original matrix: %d\n", rank);

    // Free all the matrices
    freeMatrix(m);
    freeMatrix(t);
    freeMatrix(n);
    freeMatrix(a);
    freeMatrix(s);
    freeMatrix(mult);

    return 0;
}
