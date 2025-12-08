#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    unsigned long long *mins = malloc((size_t)n * sizeof(unsigned long long));
    unsigned long long *vals = malloc((size_t)n * sizeof(unsigned long long));
    char op[6];
    int top = 0;
    while(n--){
        scanf("%s",op);
        if(op[0]=='P' && op[1]=='U'){ /* PUSH */
            unsigned long long x;
            scanf("%llu",&x);
            vals[top]=x;
            if(top==0) mins[top]=x;
            else mins[top]= (x < mins[top-1]) ? x : mins[top-1];
            top++;
        } else if(op[0]=='P' && op[1]=='O'){ /* POP */
            if(top==0) printf("EMPTY\n");
            else top--;
        } else { /* MIN */
            if(top==0) printf("EMPTY\n");
            else printf("%llu\n", mins[top-1]);
        }
    }
    free(mins);
    free(vals);
    return 0;
}
