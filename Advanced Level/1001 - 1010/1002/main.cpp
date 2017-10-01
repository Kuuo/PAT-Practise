#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

double ret[MAX];

int main() {
    int n, k;
    double c;
    for (int j = 0; j < 2; ++j) {
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d %lf", &n, &c);
            ret[n] += c;
        }
    }

    int cnt = 0, flag;
    for (int i = MAX - 1; i >= 0; i--) {
        flag = fabs(ret[i] - 0) > 1e-4;
        if (flag) cnt++;
    }

    printf("%d", cnt);
    for (int i = MAX - 1; i >= 0; i--) {
        flag = fabs(ret[i] - 0) > 1e-4;
        if (flag) printf(" %d %.1f", i, ret[i]);;
    }

    return 0;
}
