#include <stdio.h>

int main()
{
    int rows, cols, i, j;

    // Получаем размеры матрицы от пользователя
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Получаем элементы матрицы от пользователя
    printf("Введите элементы матрицы:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Транспонируем матрицу
    int transpose[cols][rows];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Выводим транспонированную матрицу
    printf("Транспонированная матрица:\n");

    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
