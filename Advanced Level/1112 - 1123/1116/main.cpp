#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int trank[MAXN];

int isprime(int n) {
    if (n < 2) return 0;
    if (n < 4) return 1;
    if ((n & 1) == 0) return 0;

    int ub = sqrt(n);
    for (int i = 2; i <= ub; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int id;
        scanf("%d", &id);
        trank[id] = i;
    }

    int k;
    scanf("%d", &k);
    string output;
    for (int i = 0; i < k; ++i) {
        int query;
        scanf("%d", &query);
        int r = trank[query];
        if (r == 0) {
            output = "Are you kidding?";
        } else if (r == -1) {
            output = "Checked";
        } else if (r == 1) {
            output = "Mystery Award";
            trank[query] = -1;
        } else if (isprime(r)) {
            output = "Minion";
            trank[query] = -1;
        } else {
            output = "Chocolate";
            trank[query] = -1;
        }
        printf("%04d: %s\n", query, output.c_str());
    }

    return 0;
}
