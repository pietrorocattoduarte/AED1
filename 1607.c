#include <stdio.h>
#include <string.h>

typedef struct {
    char a, b;
} Pair;

Pair stack[200000];
int top;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char A[100005], B[100005];
        scanf("%s %s", A, B);

        int len = strlen(A);
        long long total = 0;

        top = -1;
        for (int i = 0; i < len; i++) {
            stack[++top].a = A[i];
            stack[top].b = B[i];
        }

        while (top >= 0) {
            char a = stack[top].a;
            char b = stack[top].b;
            top--;

            int aa = a - 'a';
            int bb = b - 'a';

            total += (bb - aa + 26) % 26;
        }

        printf("%lld\n", total);
    }

    return 0;
}
