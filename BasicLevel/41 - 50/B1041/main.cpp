#include <bits/stdc++.h>
using namespace std;

struct info {
    string eid;
    int sid;
};

map<int, info> maps;
int n, m;

int main() {
    scanf("%d", &n);
    string t1;
    int t2, t3;
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2 >> t3;
        maps[t2] = {t1, t3};
    }

    scanf("%d", &m);
    int k;
    info ti;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        ti = maps[k];
        cout << ti.eid << " " << ti.sid << endl;
    }

    return 0;
}
