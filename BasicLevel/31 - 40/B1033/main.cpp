#include <bits/stdc++.h>
using namespace std;

char broken[300];
char input[100005];

int main() {
    gets(input);
    for (int i = 0; input[i]; ++i) {
        broken[input[i]] = 1;
        broken[tolower(input[i])] = 1;
    }

    char ch;
    while (scanf("%c", &ch) != EOF) {
        if (broken['+'] && isupper(ch)) continue;
        if (!broken[ch]) putchar(ch);
    }

    return 0;
}
