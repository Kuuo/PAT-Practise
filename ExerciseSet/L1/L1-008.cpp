#include <cstdio>

int main () {

    int from, to;
    scanf("%d %d", &from, &to);

    int sum = 0, cnt = 1;
    for (int i = from; i < to + 1; i++, cnt++)
    {
        sum += i;
        printf("%5d", i);
        if (i == to) { printf("\n"); break; }
        else if (cnt % 5 == 0) printf("\n");
    }
    printf("Sum = %d", sum);

    return 0;
}