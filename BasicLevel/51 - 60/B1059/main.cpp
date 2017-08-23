#include <bits/stdc++.h>
using namespace std;

int n, k;
int rankd[10005];

int isprime(int n) {
    if (n < 4) return 1;
    int m = sqrt(n);
    for (int i = 2; i <= m; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    int cid;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cid);
        rankd[cid] = i + 1;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &cid);
        printf("%04d: ", cid);
        if (rankd[cid] == 0) {
            printf("Are you kidding?\n");
        } else if (rankd[cid] == -1) {
            printf("Checked\n");
        } else {
            if (rankd[cid] == 1) {
                printf("Mystery Award\n");
            } else if (isprime(rankd[cid])) {
                printf("Minion\n");
            } else {
                printf("Chocolate\n");
            }
            rankd[cid] = -1;
        }
    }

    return 0;
}
