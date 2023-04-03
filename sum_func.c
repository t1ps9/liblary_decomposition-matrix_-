#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_sum(int m, int n, int **matrix1, int **matrix2, int **result) {
//     printf("Заполнение матриц случайными значениями...\n");
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             matrix1[i][j] = rand() % 10;
//             matrix2[i][j] = rand() % 10;
//         }
//     }
    
    //    можно оставить рандомное заполнение матриц , а можно и передовать в функцию из main

    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
