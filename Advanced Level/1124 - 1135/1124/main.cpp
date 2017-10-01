#include <bits/stdc++.h>
using namespace std;

int m, n, s;
vector<string> data;

int main() {
    scanf("%d %d %d", &m, &n, &s);

    if (s > m) {
        printf("Keep going...\n");
        return 0;
    }

    data.resize(m + 1);
    for (int i = 0; i < m; ++i) {
        string name;
        cin >> name;
        data[i + 1] = name;
    }

    set<string> winner;
    int i = s;
    while (i <= m) {
        if (winner.find(data[i]) != winner.end()) {
            i++;
        } else {
            cout << data[i] << endl;
            winner.insert(data[i]);
            i += n;
        }
    }

    return 0;
}
