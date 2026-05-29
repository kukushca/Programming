#include "struct.h"
#include <stdio.h>

triangle_t* input_triangles(int n) {
    triangle_t *arr = malloc(n * sizeof(*arr));
    
    printf("Введите %d треугольника:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    
    return arr;
}

void count_triangles(triangle_t *t, int n, int *k1, int *k2) {

triangle_t tr[3];
    *k1 = 0;
    *k2 = 0;
    
    for(int i = 0; i < n; i++) {
        if(t[i].a == t[i].b && t[i].b == t[i].c) {
            (*k1)++;
        }
        
        int a = t[i].a, b = t[i].b, c = t[i].c;
        if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            (*k2)++;
        }
    }
}