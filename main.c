#include <stdio.h>
#include <stdlib.h>

enum { MAX = 100 };

void transpose(int matrix[][MAX], int rows, int cols);
void matrix_sum(int m, int n, int **matrix1, int **matrix2, int **result);
void matrix_product(int m, int n, int **matrix1, int **matrix2, int **result);
int determinant(int matrix[][MAX], int n);

int main() {
    //для транспонирования
    int rows, cols;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &rows, &cols);

    int result[MAX][MAX];
    printf("Введите элементы матрицы:\n");
    int matrix;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nТранспонированная матрица:\n");
    transpose(matrix, rows, cols);

    // для суммы матриц
    int **matrix1;
    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("\nВведите элементы матрицы1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    int **matrix2;
    (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("\nВведите элементы матрицы2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    matrix_sum(rows, cols, matrix1, matrix2, result);
    printf("\nСумма матриц:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    int m1, n1, m2, n2;
    printf("\nВведите количество строк и столбцов матрицы1: ");
    scanf("%d %d", &m1, &n1);
    printf("Введите элементы матрицы1:\n");
    int **mat1 = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        mat1[i] = (int *)malloc(n1 * sizeof(int));
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nВведите количество строк и столбцов матрицы2: ");
    scanf("%d %d", &m2, &n2);
    if (n1 != m2) {
        printf("Error: Number of columns in matrix1 should be equal to number "
               "of rows in matrix2.\n");
        return 0;
    }
    printf("Введите элементы матрицы2:\n");
    //для умножения матриц
    int **mat2 = (int **)malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++) {
        mat2[i] = (int *)malloc(n2 * sizeof(int));
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    int **res = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        res[i] = (int *)malloc(n2 * sizeof(int));
    }
    matrix_product(m1, n2, mat1, mat2, res);
    printf("\nРезультат:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    int matrix[MAX][MAX];
    int det = determinant(matrix, MAX);
    printf("Определитель матрицы: %d\n", det);

    for (int i = 0; i < m1; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(res[i]);
    }
    free(mat1);
    free(mat2);
    free(res);
    return 0;
}
