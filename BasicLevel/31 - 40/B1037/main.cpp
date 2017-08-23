#include <bits/stdc++.h>
using namespace std;

int p, a, r;
int pg, ps, pk;
int ag, as, ak;
int rg, rs, rk;

int main() {
    scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);

    p = ((pg * 17) + ps) * 29 + pk;
    a = ((ag * 17) + as) * 29 + ak;

    r = a - p;
    rg = r / 17 / 29;
    r = r - rg * 17 * 29;
    rs = r / 29;
    rk = r - rs * 29;

    int isneg = rg < 0 || rs < 0 || rk < 0;
    if (isneg) printf("-");
    printf("%d.%d.%d", abs(rg), abs(rs), abs(rk));

    return 0;
}
