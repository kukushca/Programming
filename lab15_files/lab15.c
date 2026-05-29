#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    char name[64];
    int id;
    char level[32];
} Data;

void save_binary(char *filename, Data *people) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    fwrite(people, sizeof(Data), N, file);

    fclose(file);
}

void search_id(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Data people[N];
    
    fread(people, sizeof(Data), N, file);
    
    int search_id;
    printf("\nPerson ID to search: ");
    scanf("%d", &search_id);

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (people[i].id == search_id) {
            printf("Person found:\n");
            printf("%s   %d   %s \n", people[i].name, people[i].id, people[i].level);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Error: preson with ID %d not found.\n", search_id);
    }

    fclose(file);

}

int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("Usage: ./lab15 staff.csv\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Data people[N];
    char buf [128];

    printf("| %-20s | %-10s | %-15s |\n", "Name", "ID", "Level");
    printf("-------------------------------------------------------\n");

    char data[100];
    int size = sizeof(data);

    for (int i = 0; i < N; i++) {
        if (fgets(buf, sizeof(buf), file) == NULL) {
            exit(1);
        }
        sscanf(buf, "%[^;];%d;%s", people[i].name, &people[i].id, people[i].level);
        printf("| %-20s | %-10d | %-15s |\n", people[i].name, people[i].id, people[i].level);
    }

    fclose(file);

    save_binary("database.dat", people);

    search_id("database.dat");
}