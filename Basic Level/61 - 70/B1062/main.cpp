#include <bits/stdc++.h>
using namespace std;

int n1, m1, n2, m2, k;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    if (n1 * m2 > n2 * m1) {
        swap(n1, n2); swap(m1, m2);
    }

    int flag = 0;
    for (int i = 1; i < k; ++i) {
        if (gcd(k, i) != 1) continue;
        if (i * m1 <= k * n1 || i * m2 >= k * n2) continue;

        if (flag) printf(" ");
        flag = 1;
        printf("%d/%d", i, k);
    }

    return 0;
}
