#include <bits/stdc++.h>
using namespace std;

int m, n, b1, b2, t;

int main() {
    scanf("%d %d %d %d %d", &m, &n, &b1, &b2, &t);

    int input;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &input);
            if (input >= b1 && input <= b2) input = t;
            if (j > 0) printf(" ");
            printf("%03d", input);
        }
        printf("\n");
    }

    return 0;
}
