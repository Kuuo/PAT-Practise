#include <bits/stdc++.h>
using namespace std;

int n, a, b;
double mmax, temp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        temp = hypot(a, b);
        mmax = max(mmax, temp);
    }

    printf("%.2f", mmax);

    return 0;
}
