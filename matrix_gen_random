#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix with random values
struct Matrix* createMatrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;

    m->data = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            m->data[i][j] = rand() % 10;  // Random values between 0 and 9
        }
    }

    return m;
}

// Function to print a matrix
void printMatrix(Matrix* m) {
    if (m == NULL) {
        printf("Error: The matrix cannot be NULL.\n");
        return;
    }

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}
