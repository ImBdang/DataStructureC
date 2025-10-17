#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);


    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}


struct Node* createTree(int number_of_node){
    struct Node *root = NULL;
    struct Node **queu = malloc(number_of_node * sizeof(struct Node*));
    int cur = 0, index = 0;
    for (int i=0; i<number_of_node; i++){
        int data = 0;
        scanf("%d", &data);
        if (root == NULL){
            root = createNode(data);
            queu[index++] = root;
        }
        else {
            while (cur < index){
                struct Node *temp = queu[cur];
                if (temp->left == NULL){
                    temp->left = createNode(data);
                    queu[index++] = temp->left;
                    break;
                }
                else if (temp->right == NULL){
                    temp->right = createNode(data);
                    queu[index++] = temp->right;
                    break;
                }
                cur++;
            }
        }
    }
    free(queu);
    return root;
}

int main(){
    struct Node *tree = createTree(7);
    printTree(tree, 0);
}