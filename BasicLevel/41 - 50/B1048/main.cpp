#include <bits/stdc++.h>
using namespace std;

char a[105], b[105];
int lena, lenb;
char ac[] = { 'J', 'Q', 'K'};

int main() {
    scanf("%s %s", &a, &b);
    lena = strlen(a);
    lenb = strlen(b);

    int cur, diff = lena - lenb, c = lena;
    for (int i = 0; i < diff; i++, c++)  {
        if ((c & 1) == 1) {
            putchar(a[i]);
        } else {
            cur = 0 - (a[i] - '0');
            if (cur < 0) cur += 10;
            putchar(cur + '0');
        }
    }

    c = 1;
    for (int i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--, c++) {
        if ((c & 1) == 1) {
            cur = ((a[i] - '0') + (b[j] - '0')) % 13;
            if (cur > 9) b[j] = ac[cur - 10];
            else         b[j] = cur + '0';
        } else {
            cur = (b[j] - '0') - (a[i] - '0');
            if (cur < 0) cur += 10;
            b[j] = cur + '0';
        }
    }

    printf("%s", b);
    return 0;
}
