#include <bits/stdc++.h>
using namespace std;

char data[1005];
int table[30];

int main() {
    gets(data);

    char ch;
    for (int i = 0; data[i]; ++i) {
        ch = tolower(data[i]);
        if (ch >= 'a' && ch <= 'z') {
            table[ch - 'a'] ++;
        }
    }

    int maxi = 0;
    for (int i = 0; i < 30; ++i) {
        if (table[i] > table[maxi]) maxi = i;
    }
    printf("%c %d", (maxi + 'a'), table[maxi]);

    return 0;
}
