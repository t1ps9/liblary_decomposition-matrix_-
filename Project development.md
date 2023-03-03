
Какие базовые функции нам нужны:

1) Создание матрицы

2) Сложение матриц

3) Умножение матриц

Здесь мы использовали некотрые "ускорители" программы, а именно:

- Используем операции векторизации (SIMD), чтобы выполнять операции над несколькими элементами одновременно.

- Используем OpenMP для распараллеливания вычислений.

- Используем оптимизации компилятора, такие как инлайнинг функций и развертывание циклов.

- Используем матричные библиотеки, которые уже оптимизированы для работы с матрицами и обеспечивают высокую производительность.

Наше перемножение написано в [mult.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/mult.c)

Там мы используем инструкция _mm_add_epi32 для сложения двух регистров, содержащих 4 элемента типа int32_t. Эта инструкция выполняет покомпонентное сложение элементов регистров (складывает первые элементы регистров, затем вторые, третьи и четвертые). Результатом выполнения инструкции является новый регистр, содержащий суммы элементов исходных регистров.

Мы загружаем 4 элемента из первой матрицы и 4 элемента из второй матрицы в регистры row1 и row2 соответственно. Затем инструкция _mm_mul_epu32 выполняет покомпонентное умножение элементов регистров row1 и row2. Результат умножения сохраняется в регистре result_row. После завершения внутреннего цикла for, результаты из регистра result_row суммируются, чтобы получить общий результат для данного элемента матрицы.

Итак, векторизация SIMD позволяет выполнять операции сразу над несколькими элементами, что может значительно ускорить вычисления, особенно для больших матриц.
4) Поиск определителя

5) Поиск обратной матрицы

6) Ортоганализация столбцов матрицы

7) Транспонирование матрицы

8) Поиск оптимального оверсемплинга для rand svd 

9) Поиск собственных векторов и собственных значений 

10) Поиск сингулярных значений 


После этого, с помощью базовых функций, реализуется алгоритм разложения.