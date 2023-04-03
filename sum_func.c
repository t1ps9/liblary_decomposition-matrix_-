#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_sum() {
    int m, n;
    printf("Введите количество строк и столбцов матриц: ");
    scanf("%d %d", &m, &n);

    int **matrix1 = (int **)malloc(m * sizeof(int *));
    int **matrix2 = (int **)malloc(m * sizeof(int *));
    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        result[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Заполнение матриц случайными значениями...\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nРезультат сложения матриц:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
}

