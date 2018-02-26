#include <cstdio>

int main() {
    int n, diva, divb, a, b;
    scanf("%d", &n);
    while(n != 0) {
        scanf("%d %d", &diva, &divb);
        while(n--) {
            scanf("%d %d", &a, &b);
            int Q1 = a - diva;
            int Q2 = b - divb;
            
            if (!Q1 or !Q2)
                printf("divisa\n");
            else if (Q1 > 0 && Q2 > 0)
                printf("NE\n");
            else if (Q1 < 0 && Q2 > 0)
                printf("NO\n");
            else if (Q1 < 0 && Q2 < 0)
                printf("SO\n");
            else if (Q1 > 0 && Q2 < 0)
                printf("SE\n");
        }
        scanf("%d", &n);
    }
    return 0;
}