#ifndef __FOOTBALLERS_H
#define __FOOTBALLERS_H

struct footballer {
    char* name;
    int number;
    int goals;
    int price;
};

void fill(struct footballer players[], int n);
void print_footballer(struct footballer players[], int n);
void selectionSort(struct footballer players[], int n); 

#endif 



