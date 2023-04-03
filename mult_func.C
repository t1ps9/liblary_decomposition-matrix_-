#include <stdio.h>
#include <emmintrin.h> // библиотека для векторизации SIMD

enum{ M = 1024, K = 1024};

void matrix_multiply(int matrix1[][K], int matrix2[][M], int result[][M]) {
   int i, j, l;

   // заполнение матриц случайными значениями
   for(i = 0; i < M; i++) {
      for(j = 0; j < K; j++) {
         matrix1[i][j] = rand();
      }
   }
   for(j = 0; j < K; j++) {
      for(l = 0; l < M; l++) {
         matrix2[j][l] = rand();
      }
   }

   __m128i row1, row2, result_row;
   for(i = 0; i < M; i++) {
      for(l = 0; l < M; l++) {
         result_row = _mm_setzero_si128(); // обнуляем регистр результата
         for(j = 0; j < K; j += 4) { // выполняем операции над 4 элементами одновременно
            row1 = _mm_loadu_si128((__m128i*)&matrix1[i][j]); // загружаем 4 элемента из первой матрицы
            row2 = _mm_loadu_si128((__m128i*)&matrix2[j][l]); // загружаем 4 элемента из второй матрицы
            result_row = _mm_add_epi32(result_row, _mm_mul_epu32(row1, row2)); // выполняем умножение и сложение
         }
         result[i][l] = result_row[0] + result_row[1] + result_row[2] + result_row[3]; // суммируем результаты
      }
   }
}
