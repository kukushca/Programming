#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

struct room {
    char *name;
    int level;
    int number;
    char *resolution;
};

typedef struct node {
    struct room data;
    struct node *next;
} node_t;

node_t *newNode(struct room rooms) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = rooms;
    new_node->next = NULL;

    return new_node;
}

node_t* appendBack(node_t* head, struct room rooms) {
    node_t* new_node = newNode(rooms);
    if (head == NULL) {
        return new_node;
    }
    
    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_node;
    return head;
}

void printList(node_t *head) {
    node_t* cur = head;
    while (cur) {
        printf("%s -> ", cur->data.name);
        cur = cur->next;
    }
    printf("NULL\n");
}

void fill(struct room rooms[], int n){
    char *names[] = {"Boss room", "Safe room", "Big boss romm", "Monster room"};
    char *res[] = {"Easy", "Normal", "Hard"};

    srand(time(NULL));
    for (int i = 0; i < n; i++){
        rooms[i].name = names[rand() % 4];
        rooms[i].number = rand() % 100;
        rooms[i].level = rand() % 50;
        rooms[i].resolution = res[rand() % 3];

    }
}

int main() {
    struct room rooms[N]; 

    fill(rooms, N);

    node_t *head = NULL;

    for (int i = 0; i < N; i++) {
        head = appendBack(head, rooms[i]);
    }

    printList(head);
}

