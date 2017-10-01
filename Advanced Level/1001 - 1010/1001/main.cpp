#include <bits/stdc++.h>
using namespace std;

int a, b, sum;
int p1, p2;
char num[20], out[20];

int main() {
    scanf("%d %d", &a, &b);
    sum = a + b;
    sprintf(num, "%d", sum);
    int len = strlen(num);

    int commacnt = len / 3;
    if (len % 3 == 0) commacnt--;
    if (sum < 0) {
        commacnt = (len - 1) / 3;
        if ((len - 1) % 3 == 0) commacnt--;
    }

    int cnt = 0, curcommacnt = 0, len2 = 0;
    for (int i = len - 1; i >= 0; i--) {
        out[len2++] = num[i];
        cnt++;
        if (cnt % 3 == 0 && curcommacnt < commacnt) {
            out[len2++]= ',';
            curcommacnt++;
        }
    }
    out[len2] = '\0';
    for (int i = len2 - 1; i >= 0; i--) {
        printf("%c", out[i]);
    }

    return 0;
}
