// Function to free the memory allocated for a matrix
void freeMatrix(Matrix* m) {
    for(int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}
