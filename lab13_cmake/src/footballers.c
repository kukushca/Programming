#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "footballers.h"

void fill(struct footballer players[], int n){
    char *names[] = {"Ronaldo", "Messi", "Neymar", "Salah", "Van Dijk", "Mane", "Alisson", "Konate", "Isak", "Ekitike"};

    srand(time(NULL));
    for (int i = 0; i < n; i++){
        players[i].name = names[rand() % (sizeof(names) / sizeof(names[0]))];
        players[i].number = rand() % 100;
        players[i].goals = rand() % 50;
        players[i].price = (rand() % 99);
    }
}

void print_footballer(struct footballer players[], int n){
    printf("%-5s  | %-10s | %-8s | %-7s | %s\n", "№", "Name", "Number", "Goals", "Price");
    for (int i = 0; i < n; i++){
        printf("%-5d| %-10s | %-8d | %-7d | %d 000 000 €\n", i+1, players[i].name, players[i].number, players[i].goals, players[i].price);
    }
    printf("\n");
}


void selectionSort(struct footballer players[], int n) {
    int i, j, min;
    struct footballer temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (players[j].price < players[min].price) {
                min = j;
            }
        }

        temp = players[min];
        players[min] = players[i];
        players[i] = temp;
    }
}