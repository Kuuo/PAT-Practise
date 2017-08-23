#include <bits/stdc++.h>
using namespace std;

int n;
char input[10];

char mar1[14][5] = { "tret",
    "jan", "feb", "mar", "apr", "may", "jun",
    "jly", "aug", "sep", "oct", "nov", "dec", "tam" };
char mar2[13][5] = { "tret",
    "tam", "hel", "maa", "huh", "tou", "kes",
    "hei", "elo", "syy", "lok", "mer", "jou" };

map<string, int> ss { {"tret", 0},
    {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6},
    {"jly", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12},
    {"tam", 13}, {"hel", 26}, {"maa", 39}, {"huh", 52}, {"tou", 65}, {"kes", 78},
    {"hei", 91}, {"elo", 104}, {"syy", 117}, {"lok", 130}, {"mer", 143}, {"jou", 156}
};

void toe() {
    int len = strlen(input), ret;
    if (len > 4) {
        char a[5] = { input[0], input[1], input[2], '\0' };
        char b[5] = { input[4], input[5], input[6] };
        if (len > 7) {
            b[3] = input[7];
            b[4] = '\0';
        } else { b[3] = '\0'; }

        ret = ss[a] + ss[b];
    } else {
        ret = ss[input];
    }
    printf("%d\n", ret);
}

void tom() {
    int num = atoi(input);
    if (num >= 13) {
        int q = num / 13, r = num % 13;
        if (r == 0) {
            printf("%s\n", mar2[q]);
        } else {
            printf("%s %s\n", mar2[q], mar1[r]);
        }
    } else {
        printf("%s\n", mar1[num]);
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        gets(input);
        if (isdigit(input[0])) tom();
        else toe();
    }

    return 0;
}
