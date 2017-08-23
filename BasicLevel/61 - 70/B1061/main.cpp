#include <bits/stdc++.h>
using namespace std;

int stun, qusn;
int ans[105], score[105], fscore[105];

int main() {
    scanf("%d %d", &stun, &qusn);
    for (int i = 0; i < qusn; ++i) scanf("%d", &score[i]);
    for (int i = 0; i < qusn; ++i) scanf("%d", &ans[i]);

    int choose;
    for (int i = 0; i < stun; ++i) {
        for (int j = 0; j < qusn; ++j) {
            scanf("%d", &choose);
            if (choose == ans[j]) fscore[i] += score[j];
        }
    }

    for (int i = 0; i < stun; ++i) {
        printf("%d\n", fscore[i]);
    }

    return 0;
}
