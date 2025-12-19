#ifndef __STRUCT_H
#define __STRUCT_H
#include <stdlib.h>

typedef struct triangle triangle_t;

struct triangle {
    int a;
    int b;
    int c;
};

triangle_t* input_triangles(int n);
void count_triangles(triangle_t *t, int n, int *k1, int *k2);

#endif