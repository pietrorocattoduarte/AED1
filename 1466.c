#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_node(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int v) {
    if (root == NULL) return new_node(v);

    if (v < root->val)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);

    return root;
}

void level_order(Node* root) {
    if (root == NULL) return;

    Node** queue = (Node**)malloc(10000 * sizeof(Node*));
    int ini = 0, fim = 0;

    queue[fim++] = root;
    int first = 1;

    while (ini < fim) {
        Node* cur = queue[ini++];

        if (first) {
            printf("%d", cur->val);
            first = 0;
        } else {
            printf(" %d", cur->val);
        }

        if (cur->left)  queue[fim++] = cur->left;
        if (cur->right) queue[fim++] = cur->right;
    }

    printf("\n");
    free(queue);
}

void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int c = 1; c <= t; c++) {
        int n;
        scanf("%d", &n);

        Node* root = NULL;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", c);
        level_order(root);
        printf("\n");

        free_tree(root);
    }

    return 0;
}
