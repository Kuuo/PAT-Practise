#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int a1, a2, b1, b2, sum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        sum = a1 + b1;
        if (a2 != sum && b2 != sum) continue;
        if (a2 != sum) a++;
        if (b2 != sum) b++;
    }

    printf("%d %d", a, b);

    return 0;
}
