#include <bits/stdc++.h>
using namespace std;

int digit[10];
char num[1005];

int main() {
    scanf("%s", &num);

    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        digit[num[i] - '0']++;
    }

    for (int i = 0; i < 10; ++i) {
        if (digit[i] == 0) continue;
        printf("%d:%d\n", i, digit[i]);
    }

    return 0;
}
