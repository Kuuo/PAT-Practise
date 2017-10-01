#include <bits/stdc++.h>
using namespace std;

int num[100005], n;
int ret[100005], retn;
int lmax[100005], rmin[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &num[i]);

    lmax[0] = num[0] - 1;
    for (int i = 1; i < n; ++i) {
        lmax[i] = num[i] > lmax[i - 1] ? num[i] : lmax[i - 1];
    }

    rmin[n - 1] = num[n - 1] + 1;
    for (int i = n - 2; i >= 0; --i) {
        rmin[i] = num[i] < rmin[i + 1] ? num[i] : rmin[i + 1];
    }

    int k;
    for (int i = 0; i < n; ++i) {
        k = num[i];
        if (k >= lmax[i] && k <= rmin[i])
            ret[retn++] = num[i];
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
