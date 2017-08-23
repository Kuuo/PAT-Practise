#include <bits/stdc++.h>
using namespace std;

typedef struct mooncake {
    double n;
    double r;
    double d;
}mooncake;

int mcopt(mooncake lhs, mooncake rhs) {
    return lhs.d > rhs.d;
}

int numtype, needed;
mooncake all[1005];
double sum;

int main() {
    scanf("%d %d", &numtype, &needed);

    for (int i = 0; i < numtype; ++i) {
        scanf("%lf", &all[i].n);
    }
    for (int i = 0; i < numtype; ++i) {
        scanf("%lf", &all[i].r);
        all[i].d = all[i].r / all[i].n;
    }
    sort(all, all + numtype, mcopt);

    for (int i = 0; i < numtype; ++i) {
        mooncake cur = all[i];
        if (cur.n >= needed) {
            sum += needed * cur.d;
            needed = 0;
        } else {
            needed -= cur.n;
            sum += cur.r;
        }

        if (needed <= 0) break;
    }
    printf("%.2f", sum);

    return 0;
}
