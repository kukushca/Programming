#include <stdio.h>

#define R 3
#define C 3

void print_matrix(int matrix[R][C]) {
    printf("Matrix:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sums(int matrix[R][C], int row_sums[R]) {
    for (int i = 0; i < R; i++) {
        row_sums[i] = 0;
        for (int j = 0; j < C; j++) {
            row_sums[i] += matrix[i][j];
        }
    }
}

void print_sums(int row_sums[R]) {
    for (int i = 0; i < R; i++) {
        printf("Sum %d: %d\n", i + 1, row_sums[i]);
    }
}

float average(int row_sums[R]) {
    int total_sum = 0;
    for (int i = 0; i < R; i++) {
        total_sum += row_sums[i];
    }
    return (float)total_sum / R;
}

void sort_matrix(int matrix[R][C], int sorted_matrix[R][C]) {
    int row_sums[R];
    int row_in[R];
    
    sums(matrix, row_sums);
    
    for (int i = 0; i < R; i++) {
        row_in[i] = i;
    }
    
    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < R - i - 1; j++) {
            if (row_sums[j] < row_sums[j + 1]) {
                int temp_sum = row_sums[j];
                row_sums[j] = row_sums[j + 1];
                row_sums[j + 1] = temp_sum;
                
                int temp_idx = row_in[j];
                row_in[j] = row_in[j + 1];
                row_in[j + 1] = temp_idx;
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        int row1 = row_in[i];
        for (int j = 0; j < C; j++) {
            sorted_matrix[i][j] = matrix[row1][j];
        }
    }
}


int count_average(int sorted_matrix[R][C], float average_sum) {
    int count = 0;
    for (int i = 0; i < R; i++) {
        int current_sum = 0;
        for (int j = 0; j < C; j++) {
            current_sum += sorted_matrix[i][j];
        }
        if (current_sum < average_sum) {
            count++;
        }
    }
    return count;
}

int main() {
    int matrix[R][C] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    int sorted_matrix[R][C];
    int row_sums[R];
    
    print_matrix(matrix);
    
    sums(matrix, row_sums);
    printf("\n");
    print_sums(row_sums);
    
    float average_sum = average(row_sums);
    printf("\nAvarage sum: %.2f\n", average_sum);
    
    sort_matrix(matrix, sorted_matrix);
    
    print_matrix(sorted_matrix);
    
    int count = count_average(sorted_matrix, average_sum);
    printf("\nCount: %d\n", count);
    
    return 0;
}