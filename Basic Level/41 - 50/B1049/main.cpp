#include <bits/stdc++.h>
using namespace std;

double input, sum;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &input);
        sum += input * (i + 1) * (n - i);
    }
    printf("%.2f", sum);

    return 0;
}
