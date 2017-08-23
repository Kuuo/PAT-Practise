#include <bits/stdc++.h>
using namespace std;

int n1[105], n2[105];
int n;

int isInsertion() {
    int firstchaos = -1;
    for (int i = 1; i < n; ++i) {
        if (n2[i] < n2[i - 1]) {
            firstchaos = i;
            break;
        }
    }
    for (int i = firstchaos; i < n; ++i) {
        if (n1[i] != n2[i]) return 0;
    }
    sort(n1, n1 + firstchaos + 1);
    printf("Insertion Sort\n");
    return 1;
}

void doMerge() {
    int last = 0, j = 0;
    for (int i = 2; i <= n; i *= 2) {
        if (equal(n1, n1 + n, n2)) last = 1;
        for (j = 0; j < n / i; j++) {
            sort(n1 + j * i, n1 + j * i + i);
        }
        sort(n1 + n / i * i, n1 + n);
        if (last) break;
    }

    printf("Merge Sort\n");
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &n1[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &n2[i]);

    if (!isInsertion()) doMerge();
    for (int i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", n1[i]);
    }
    return 0;
}
