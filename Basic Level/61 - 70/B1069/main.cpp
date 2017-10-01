#include <bits/stdc++.h>
using namespace std;

int m, n, s;
set<string> gotted;

int main() {
    scanf("%d %d %d", &m, &n, &s);
    if (m < s) {
        printf("Keep going...");
        return 0;
    }

    string input;
    int index = 0, started = 0, keepindex = 0;
    for (int i = 0; i < m; ++i) {
        cin >> input;
        if (i + 1 == s) {
            started = 1;
            gotted.insert(input);
            cout << input << '\n';
            continue;
        }
        if (!started) continue;
        if (!keepindex) index++;
        if (index == n) {
            if (gotted.find(input) != gotted.end()) {
                keepindex = 1;
                continue;
            }
            keepindex = 0;
            gotted.insert(input);
            cout << input << '\n';
            index = 0;
        }
    }

    return 0;
}
