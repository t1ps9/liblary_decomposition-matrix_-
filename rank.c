// Swap rows
void swap_rows(int* row1, int* row2, int cols) {
    for(int i = 0; i < cols; i++) {
        int temp = row1[i];
        row1[i] = row2[i];
        row2[i] = temp;
    }
}

// Function to calculate the rank of a matrix
int rankMatrix(Matrix* m) {
    int rank = 0;

    for(int i = 0; i < m->rows; ++i) {
        // Find the pivot row
        int pivotRow = -1;
        for(int j = i; j < m->rows; ++j) {
            if(m->data[j][i] != 0) {
                pivotRow = j;
                break;
            }
        }

        // If no pivot row was found, then this column does not contribute to the rank
        if(pivotRow == -1) {
            continue;
        }

        // Swap the pivot row with the current row
        if(pivotRow != i) {
            swap_rows(m->data[pivotRow], m->data[i], m->cols);
        }

        // Normalize the row based on the pivot
        int pivot = m->data[i][i];
        for(int j = i; j < m->cols; ++j) {
            m->data[i][j] /= pivot;
        }

        // Subtract multiples of the pivot row from all the other rows
        for(int j = 0; j < m->rows; ++j) {
            if(i != j) {
                int multiplier = m->data[j][i];
                for(int k = i; k < m->cols; ++k) {
                    m->data[j][k] -= multiplier * m->data[i][k];
                }
            }
        }

        // Increment the rank
        ++rank;
    }

    return rank;
}
