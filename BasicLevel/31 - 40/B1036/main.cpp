#include <bits/stdc++.h>
using namespace std;

int n, r;
char c;

void putnc(char c, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        putchar(c);
    }
}

int main() {
    scanf("%d %c", &n, &c);
    r = (int)(n / 2.0 + 0.5);

    putnc(c, n);
    printf("\n");
    for (int i = 0; i < r - 2; ++i) {
        putchar(c);
        putnc(' ', n - 2);
        putchar(c);
        printf("\n");
    }
    putnc(c, n);

    return 0;
}
