#include <bits/stdc++.h>
using namespace std;
#define MAXN 505

int numv, nume;
int degree[MAXN];
int uf[MAXN], isvalid[MAXN];

void init() { for (int i = 0; i < MAXN; ++i) uf[i] = i; }
int find(int x) { return uf[x] == x ? x : uf[x] = find(uf[x]); }
void merge(int x, int y) { uf[find(x)] = find(y); }
int cc() {
    int ret = 0;
    for (int i = 1; i <= numv; ++i) {
        if (isvalid[i] && uf[i] == i) ret++;
    }
    return ret;
}

int main() {
    scanf("%d %d", &numv, &nume);
    init();
    for (int i = 0; i < nume; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        degree[a]++;
        degree[b]++;
        merge(a, b);
        isvalid[a] = isvalid[b] = 1;
    }

    int numeven = 0, numodd = 0;
    for (int i = 1; i <= numv; ++i) {
        if (i != 1) printf(" ");
        printf("%d", degree[i]);
        if ((degree[i] & 1) == 0) {
            numeven++;
        } else numodd++;
    }

    printf("\n");

    int ccount = cc();
    if (ccount > 1) {
        printf("Non-Eulerian");
        return 0;
    }

    if (numodd == 0) {
        printf("Eulerian");
    } else if (numodd == 2) {
        printf("Semi-Eulerian");
    } else {
        printf("Non-Eulerian");
    }

    return 0;
}
