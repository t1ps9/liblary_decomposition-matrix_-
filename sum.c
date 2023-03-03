#include <stdio.h>

int main() {
   int m, n;
   printf("Введите количество строк и столбцов матриц: ");
   scanf("%d %d", &m, &n);

   int matrix1[m][n], matrix2[m][n], result[m][n];
   int i, j;

   printf("\nВведите элементы первой матрицы:\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("\nВведите элементы второй матрицы:\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }

   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         result[i][j] = matrix1[i][j] + matrix2[i][j];
      }
   }

   printf("\nРезультат сложения матриц:\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         printf("%d ", result[i][j]);
      }
      printf("\n");
   }

   return 0;
}
