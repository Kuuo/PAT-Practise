#include <cstdio>
#define LIMIT 11

int table[LIMIT] = { 0, 1, 2, 6, 24, 120, 720 };

void init() {
    for (int i = 3; i < LIMIT; ++i) {
        table[i] = table[i - 1] * i;
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += table[i];
    }
    printf("%d", sum);

    return 0;
}