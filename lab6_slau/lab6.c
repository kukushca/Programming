#include <stdio.h>

int opred_2 (int a, int b, int c, int d) {
    return a * d - b * c;
}
int opred_3 (int matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])  + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main () {
    int n = 3;
    int matrix[3][3] = {
        {2, -3, 1},
        {1, 2, -3},
        {-1, -1, 5}
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
    printf("\n");
    }
    printf("введите свободные члены: ");
    int b[3];
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int main_det;
    if (n == 2) {
        main_det = opred_2(matrix[0][0], matrix[0][1], matrix[1][0],matrix[1][1]);
    }
    else {
        main_det = opred_3(matrix);
    }
    if (main_det == 0) {
        printf("система не имеет единственного решения\n");
        return 1;
    } 
    

    if (n == 2) {
        int det_x = opred_2(b[0], matrix[0][1], b[1], matrix[1][1]);
        int det_y = opred_2(matrix[0][0], b[0], matrix[1][0], b[1]);
        float x = det_x / main_det;
        float y = det_y / main_det;
        printf("ответ: x = %.1f, y = %.1f\n", x, y); 
    }
    else if (n == 3) {
        int deter_X[3][3] = {
            {b[0], matrix[0][1], matrix[0][2]},
            {b[1], matrix[1][1], matrix[1][2]},
            {b[2], matrix[2][1], matrix[2][2]}
        };
        int d_x = opred_3(deter_X);
        int deter_y[3][3] = {
            {matrix[0][0], b[0], matrix[0][2]},
            {matrix[1][0], b[1], matrix[1][2]},
            {matrix[2][0], b[2], matrix[2][2]}
        };
        int d_y = opred_3(deter_y);
        int deter_z[3][3] = {
            {matrix[0][0], matrix[0][1], b[0]},
            {matrix[1][0], matrix[1][1], b[1]},
            {matrix[2][0], matrix[2][1], b[2]}
        };

        int d_z = opred_3(deter_z);

        float x = d_x / main_det;
        float y = d_y / main_det;
        float z = d_z / main_det;

        printf("ответ: x = %.1f, y = %.1f, z = %.1f\n", x, y, z);
    }
}