#include "struct.h"
#include <stdio.h>

int main() {
    int n, k1, k2;
    
    printf("n = ");
    scanf("%d", &n);
    
    triangle_t *arr = input_triangles(n);
    count_triangles(arr, n, &k1, &k2);
    
    printf("k1 = %d\nk2 = %d\n", k1, k2);
    
    free(arr);
    return 0;
}