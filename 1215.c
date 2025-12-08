#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char *word;
    struct Node *left, *right;
} Node;

char *my_strdup(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = malloc(n);
    if (!p) return NULL;
    memcpy(p, s, n);
    return p;
}

Node *new_node(const char *word) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->word = my_strdup(word);
    if (!n->word) { perror("malloc"); exit(EXIT_FAILURE); }
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, const char *word) {
    if (!root) return new_node(word);
    int cmp = strcmp(word, root->word);
    if (cmp < 0) root->left = insert(root->left, word);
    else if (cmp > 0) root->right = insert(root->right, word);
    return root;
}

void inorder_print(Node *root) {
    if (!root) return;
    inorder_print(root->left);
    printf("%s\n", root->word);
    inorder_print(root->right);
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->word);
    free(root);
}

int main(void) {
    char line[1005];
    Node *root = NULL;

    char word[1005];
    int wlen = 0;

    while (fgets(line, sizeof(line), stdin)) {
        for (int i = 0; line[i] != '\0'; ++i) {
            if (isalpha((unsigned char)line[i])) {
                if (wlen < (int)sizeof(word)-1) {
                    word[wlen++] = (char)tolower((unsigned char)line[i]);
                }
            } else {
                if (wlen > 0) {
                    word[wlen] = '\0';
                    root = insert(root, word);
                    wlen = 0;
                }
            }
        }

        if (wlen > 0) {
            word[wlen] = '\0';
            root = insert(root, word);
            wlen = 0;
        }
    }

    inorder_print(root);
    free_tree(root);
    return 0;
}
