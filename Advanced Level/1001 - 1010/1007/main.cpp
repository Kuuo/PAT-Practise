#include <bits/stdc++.h>
using namespace std;

int k, sum = -1, bi, ei;
int num[10005];
int allnegative = 1;

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &num[i]);
        if (num[i] >= 0) allnegative = 0;
    }

    if (allnegative) {
        printf("%d %d %d", 0, num[0], num[k - 1]);
        return 0;
    }

    int cursum = 0;
    for (int i = 0; i < k; ++i) {
        cursum = 0;
        for (int j = i; j < k; ++j) {
            cursum += num[j];
            if (cursum > sum) {
                sum = cursum;
                bi = i;
                ei = j;
            }
        }
    }

    printf("%d %d %d", sum, num[bi], num[ei]);
    return 0;
}
