#include <bits/stdc++.h>
using namespace std;

long a, b, sum;
int base;
int ret[55];

int main() {
    scanf("%ld %ld %d", &a, &b, &base);
    sum = a + b;

    int ptr = 0;
    do {
        ret[ptr++] = sum % base;
        sum /= base;
    } while (sum != 0);

    for (int i = ptr - 1; i >= 0; i--) {
        printf("%d", ret[i]);
    }

    return 0;
}
