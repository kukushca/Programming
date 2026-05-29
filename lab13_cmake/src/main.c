#include <stdio.h>
#include "footballers.h"
#include <sys/time.h>

#define N 100000

int main(){
    struct footballer players[N];
    struct timeval start, end;
    long time_diff;

    fill(players, N);
    printf("До сортировки:\n");
    print_footballer(players, N);

    gettimeofday(&start, NULL);

    selectionSort(players, N);

    gettimeofday(&end, NULL);

    printf("После сортировки:\n");
    print_footballer(players, N);

    time_diff = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printf("Время сортировки для %d: %ld мкс\n", N, time_diff);
    return 0;
}