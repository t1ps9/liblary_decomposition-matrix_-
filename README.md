# liblary_decomposition-matrix_C
Библиотека на С для разных разложений матриц

Задача: написать библиотеку на языке С для разных видов разложений матриц

Функционал:

1) SVD разложение - определённого типа разложение прямоугольной матрицы, имеющее широкое применение, в силу своей наглядной геометрической интерпретации, при решении многих прикладных задач

2) собственное разложение - это факторизация матрицы в каноническую форму , посредством чего матрица представлена ​​в терминах своих собственных значений и собственных векторов 

3) rand SVD - рандомный алгоритм SVD (работает быстрее обычного и не сильно теряется точность)

4) QR - представление матрицы в виде произведения унитарной (или ортогональной матрицы) и верхнетреугольной матрицы.

5) побочные функции, нужные для этих разложений (умножения матриц, обращение матриц, искать ортогональные матрицы)

--------------------

Разбиение задач:

Максим Забелин:

Изучил все "ускорители", прочитал про различные библиотеки для них. Провел тесты для сравнения результатов обычного умножения и сложения со соответсвующими
ускоренными программами. Написал описание программ в [Project development.md](https://github.com/t1ps9/liblary_decomposition-matrix_-/blob/main/Project%20development.md)

Нигматзянов Тимур:

На основе знаний Максима написал код, который вычисляет ускоренные сумму и умножения матриц. Написал комментарии к программам
