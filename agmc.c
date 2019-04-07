#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *right, *left;
} Node;

int root_index = 0;

Node *makeTree(char (*preOrder)[], char (*inOrder)[], int start, int end) {
    if (start > end) return NULL;
    int index = 0;

    Node *root = malloc(sizeof(Node));
    root->data = (*preOrder)[root_index++];

    for(int i = 0; i <= end; i++) {
        if ((*inOrder)[i] == root->data) index = i;
    }

    root->left = makeTree(preOrder, inOrder, start, index - 1);
    root->right = makeTree(preOrder, inOrder, index + 1, end);
    return root;
}

void printPostOrder(Node *node) {
    if (node == NULL) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%c", node->data);
}

int main() {
    int amount_tests, amount_nodes;
    char preOrder[53], inOrder[53];
    char (*preOrder_pointer)[] = &preOrder;
    char (*inOrder_pointer)[] = &inOrder;

    scanf("%d", &amount_tests);

    while(amount_tests--) {
        root_index = 0;
        scanf("%d %s %s", &amount_nodes, preOrder, inOrder);
        Node *root = malloc(amount_nodes*sizeof(Node));
        root = makeTree(preOrder_pointer, inOrder_pointer, 0, amount_nodes - 1);
        printPostOrder(root);
        printf("\n");
        free(root);
    }
    return 0;
}
