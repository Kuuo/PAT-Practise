#include <bits/stdc++.h>
using namespace std;

int input[100005], n;
int ret[100005], retn;
int lmax[100005], rmin[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &input[i]);

    lmax[0] = input[0] - 1;
    for (int i = 1; i < n; ++i) {
        lmax[i] = input[i] > lmax[i - 1] ? input[i] : lmax[i - 1];
    }

    rmin[n - 1] = input[n - 1] + 1;
    for (int i = n - 2; i >= 0; --i) {
        rmin[i] = input[i] < rmin[i + 1] ? input[i] : rmin[i + 1];
    }

    int k;
    for (int i = 0; i < n; ++i) {
        k = input[i];
        if (k >= lmax[i] && k <= rmin[i])
            ret[retn++] = input[i];
    }

    sort(ret, ret + retn);
    printf("%d\n", retn);
    for (int i = 0; i < retn; ++i) {
        if (i > 0) printf(" ");
        printf("%d", ret[i]);
    }
    printf("\n");

    return 0;
}
