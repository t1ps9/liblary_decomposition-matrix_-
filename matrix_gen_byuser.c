// Function to create a new matrix with user input
Matrix* createUserMatrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;

    m->data = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            printf("Enter value for cell [%d][%d]: ", i, j);
            scanf("%d", &(m->data[i][j]));
        }
    }

    return m;
}
