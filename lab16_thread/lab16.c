#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE 50


char *strings[4][5] = {
    {"1", "1", "1", "1", "1"},
    {"2", "2", "2", "2", "2"},
    {"3", "3", "3", "3", "3"},
    {"4", "4", "4", "4", "4"}
};


void *message_from_thread(void *args) {
    for (int i = 1; i <= 5; i++) {
        printf("Дочерний поток: строка %d\n", i);
    }
    return NULL;
}


void last_message(void *args) {
    printf("Дочерний поток заверишил свою работу\n");
}

void *print_strings(void *args) {
    int thread_num = *(int *)args;

    pthread_cleanup_push(last_message, NULL);

    for (int i = 0; i < 5; i++) {
        printf("Поток %d: %s\n", thread_num + 1, strings[thread_num][i]);
        sleep(1);
    }

    pthread_cleanup_pop(1);
    return NULL;
}

void *sleep_sort(void *args) {
    int value = *(int *)args;
    sleep(value);
    printf("%d ", value);
    fflush(stdout);
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, message_from_thread, NULL);
    
    pthread_join(thread, NULL); 
    
    for (int i = 1; i <= 5; i++) {
        printf("Родительский поток: строка %d\n", i);
    }


    pthread_t threads[4];
    int thread_nums[4];

    for (int i = 0; i < 4; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, print_strings, &thread_nums[i]);
    }

    sleep(2);

    printf("Главный поток прерывает работу дочерних потоков\n");
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    int n;
    int numbers[MAX_SIZE];

    printf("Введите количество элементов (не более %d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Некорректный размер массива.\n");
        return 1;
    }

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    pthread_t sort_threads[MAX_SIZE];
    printf("Массив после SleepSort: ");
    fflush(stdout);

    for (int i = 0; i < n; i++) {
        pthread_create(&sort_threads[i], NULL, sleep_sort, &numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(sort_threads[i], NULL);
    }
    printf("\n");

}
