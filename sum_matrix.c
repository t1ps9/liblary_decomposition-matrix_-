#include <stdio.h>
#include <stdlib.h> // библиотека для использования функции malloc и free
#include <omp.h> // библиотека для параллельных вычислений с использованием OpenMP

int main() {
   int m, n;
   printf("Введите количество строк и столбцов матриц: ");
   scanf("%d %d", &m, &n);

   // динамическое выделение памяти для матриц
   int **matrix1 = (int **)malloc(m * sizeof(int *));
   int **matrix2 = (int **)malloc(m * sizeof(int *));
   int **result = (int **)malloc(m * sizeof(int *));
   for (int i = 0; i < m; i++) {
      matrix1[i] = (int *)malloc(n * sizeof(int));
      matrix2[i] = (int *)malloc(n * sizeof(int));
      result[i] = (int *)malloc(n * sizeof(int));
   }

   printf("\nВведите элементы первой матрицы:\n");
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("\nВведите элементы второй матрицы:\n");
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }

   // параллельное выполнение циклов, которые проходят через матрицы и складывают их элементы
   #pragma omp parallel for
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         result[i][j] = matrix1[i][j] + matrix2[i][j];
      }
   }

   printf("\nРезультат сложения матриц:\n");
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         printf("%d ", result[i][j]);
      }
      printf("\n");
   }

   // освобождение памяти, которую мы выделили для матриц
   for (int i = 0; i < m; i++) {
      free(matrix1[i]);
      free(matrix2[i]);
      free(result[i]);
   }
   free(matrix1);
   free(matrix2);
   free(result);

   return 0;
}
