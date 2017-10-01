#include <bits/stdc++.h>
using namespace std;

struct person {
    char name[10];
    int y, m, d;
} input[100006], valid[100006];

int popt(person a, person b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int isvalid(person p) {
    if (p.y < 1814 || p.y > 2014) return 0;
    if (p.y == 1814) {
        if (p.m < 9) return 0;
        if (p.m == 9 && p.d < 6) return 0;
    }
    if (p.y == 2014) {
        if (p.m > 9) return 0;
        if (p.m == 9 && p.d > 6) return 0;
    }
    return 1;
}

int n, numvalid;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d/%d/%d", &input[i].name, &input[i].y, &input[i].m, &input[i].d);
        if (isvalid(input[i])) {
            valid[numvalid++] = input[i];
        }
    }
    n = numvalid;

    printf("%d", n);
    if (n > 0) {
        sort(valid, valid + n, popt);

        char* maxn = valid[n - 1].name;
        char* minn = valid[0].name;

        printf(" %s %s\n", minn, maxn);
    }

    return 0;
}
