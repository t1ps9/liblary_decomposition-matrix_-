
## Какие базовые функции нам нужны:

1) Создание матрицы

2) Сложение матриц

Здесь мы использовали некотрые "ускорители" программы, а именно:

- Используем динамическое выделение памяти для матриц с помощью функции malloc
- Используем параллельные вычисления с помощью директивы #pragma omp parallel for и функции omp_get_num_procs, чтобы использовать все доступные процессоры. Это ускоряет выполнение циклов, которые проходят через матрицы и складывают их элементы.
- Освобождаем память, которую мы выделили для матриц, используя функцию free.

Наше суммирование матриц написано в [sum.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/sum.c)

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

4) Нахождение транспонированной матрицы

Реализовано в [transpose.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/transpose.c)

## К КТ5(все ниже реализованное, сделано после КТ4):

- Обернули написанные коды в функции:

функция для суммы - [sum_func.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/sum_func.c)

функция для перемножения - [mult_func.C](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/mult_func.C)

функция для транспонирования - [transpose_func.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/transpose_func.c)

функция для нахождения определителя матрицы - [det.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/det.c)


- Написали main, в котором можно вызвать написанные функции
[main.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/main.c)
- Дописали функции, реализованные ниже

- Изучаем теоритескиую часть алгоритмов, которые используют быстрые операции

Изученные статьи: 
- https://habr.com/ru/post/21042/
- https://habr.com/ru/post/359272/

5) Поиск определителя

Нахождение определителя реализовано в функции [det.c](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/det.c)


## Дополнительная Разработка:
- Подбор оптимальных алгоритмов для реализаций основных функций, описанных в "базовые функции"
- Реализация других функций и алгоритмов и написание кода к ним:
6) Поиск обратной матрицы

7) Ортоганализация столбцов матрицы

8) Транспонирование матрицы

9) Поиск оптимального оверсемплинга для rand svd 

10) Поиск собственных векторов и собственных значений 

11) Поиск сингулярных значений 
12) реализация svd разложение [svd.c]()

- Создание библиотеки со всеми функциями и взаимодействия с ними
- Создание удобного интерфейса для взаимодействия с нашей программой 
