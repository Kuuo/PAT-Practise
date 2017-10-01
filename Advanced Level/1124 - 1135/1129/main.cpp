#include <bits/stdc++.h>
using namespace std;

int n, k, q;
int acctime[50005];
typedef struct item {
    int index = 0, acctime = 0;
    item(int i = 0, int at = 0) : index(i), acctime(at) {}
} item;

int cmp(item a, item b) {
    if (a.acctime != b.acctime) return a.acctime > b.acctime;
    return a.index < b.index;
}

set<item, decltype(*cmp)> rec(*cmp);

void add(int index) {
    acctime[index]++;
    auto it = rec.find(item(index, acctime[index] - 1));
    if (it == rec.end()) rec.insert(item(index, 1));
    else {
        rec.erase(it);
        rec.insert(item(index, acctime[index]));
    }
}

int main() {
    scanf("%d %d", &n, &k);
    scanf("%d", &q);
    add(q);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &q);
        printf("%d:", q);

        auto ub = min((int)rec.size(), k);
        int j = 0;
        for (auto it = rec.begin(); j < ub && it != rec.end(); it++, j++) printf(" %d", it->index);
        printf("\n");
        add(q);
    }

    return 0;
}
