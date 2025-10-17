#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head){
    if (head == NULL){
        printf("List is null");
        return;
    }
    while (head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

void pushList(struct Node **head, struct Node *newNode){
    newNode->next = *head;
    *head = newNode;
}

void popList(struct Node **head){
    if (*head == NULL)
        return;
    struct Node *cur = *head;
    *head = (*head)->next;
    free(cur);
}

struct Node* createStack(int number_of_stack){
    struct Node* head = NULL;
    for (int i=0; i<number_of_stack; i++){
        int data = 0;
        scanf("%d", &data);
        if (head == NULL){
            head = createNode(data);
        }
        else{
            struct Node *newNode = createNode(data);
            newNode->next = head;
            head = newNode;
        }
    }
    return head;
}

struct Node* createQueu(int number_of_stack){
    struct Node* head = NULL;
    struct Node* last = NULL;
    for (int i=0; i<number_of_stack; i++){
        int data = 0;
        scanf("%d", &data);
        if (head == NULL){
            head = createNode(data);
            last = head;
        }
        else{
            struct Node *newNode = createNode(data);
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

int main(){
    // struct Node *stack = NULL;
    // stack = createStack(5);
    // struct Node *newN = createNode(6);
    // pushList(&stack, newN);

    struct Node *queu = NULL;
    queu = createQueu(5);

    printList(queu);
    return 0;
}