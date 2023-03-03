#include <stdio.h>

int main() {
   int m, n, k;
   printf("Введите количество строк и столбцов первой матрицы: ");
   scanf("%d %d", &m, &n);
   printf("Введите количество столбцов второй матрицы: ");
   scanf("%d", &k);

   int matrix1[m][n], matrix2[n][k], result[m][k];
   int i, j, l;

   printf("\nВведите элементы первой матрицы:\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("\nВведите элементы второй матрицы:\n");
   for(j = 0; j < n; j++) {
      for(l = 0; l < k; l++) {
         scanf("%d", &matrix2[j][l]);
      }
   }

   for(i = 0; i < m; i++) {
      for(l = 0; l < k; l++) {
         result[i][l] = 0;
         for(j = 0; j < n; j++) {
            result[i][l] += matrix1[i][j] * matrix2[j][l];
         }
      }
   }

   printf("\nРезультат умножения матриц:\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < k; j++) {
         printf("%d ", result[i][j]);
      }
      printf("\n");
   }

   return 0;
}
