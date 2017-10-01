#include <bits/stdc++.h>
using namespace std;

int n;
double sum, num[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf", &num[i]);

    for (int i = 0; i < n; ++i) {
        sum += num[i] * (i + 1) * (n - i);
    }

    printf("%.2f", sum);
    return 0;
}
