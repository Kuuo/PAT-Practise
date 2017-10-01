#include <bits/stdc++.h>
using namespace std;

char letters[] = { 'P', 'A', 'T', 'e', 's', 't' };
int n[6];

int main() {
    char ch;
    while (scanf("%c", &ch) != EOF) {
        if (ch == 'P') n[0]++;
        if (ch == 'A') n[1]++;
        if (ch == 'T') n[2]++;
        if (ch == 'e') n[3]++;
        if (ch == 's') n[4]++;
        if (ch == 't') n[5]++;
    }

    int mini;
    while (true) {
        for (mini = 0; mini < 6 && n[mini] <= 0; ++mini);
        if (mini == 6) break;

        for (int i = mini; i < 6; ++i) {
            if (n[i] <= 0) continue;
            n[i]--;
            printf("%c", letters[i]);
        }
    }

    return 0;
}
