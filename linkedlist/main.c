#include <stdio.h>
#include <stdlib.h>

struct linked_list{
    int data;
    struct linked_list *next;
};

void free_all(struct linked_list **head){
    struct linked_list *last = *head;
    while (last != NULL){
        struct linked_list *cur = last;
        last = last->next;
        free(cur);
    }
    *head = NULL;
    printf("Freed all the pointers");
}

int main(){
    struct linked_list *head = NULL;
    struct linked_list *tail = NULL;
    int n = 5;
    for (int i = 0; i < n; i++) {
        struct linked_list *newNode = malloc(sizeof(struct linked_list));
        newNode->data = i;    
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    short i = 0;
    for (struct linked_list *iNode = head; iNode != NULL; iNode = iNode->next){
        i = i + 1;
    }
    printf("%hd", i);
    free_all(&head);
    return 0;
}