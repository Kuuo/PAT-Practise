#include <bits/stdc++.h>
using namespace std;

int toll[24], n;

typedef struct record {
    int month, day, h, m;
    int online;
} record;

int cmp(record a, record b) {
    if (a.month == b.month) {
        if (a.day == b.day) {
            if (a.h == b.h) return a.m < b.m;
            return a.h < b.h;
        }
        return a.day < b.day;
    }
    return a.month < b.month;
}

map<string, vector<record>> data;

int main() {
    for (int i = 0; i < 24; ++i) scanf("%d", &toll[i]);
    scanf("%d", &n);

    string name, stat;
    int m, d, h, mm;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        scanf("%d:%d:%d:%d", &m, &d, &h, &mm);
        cin >> stat;
        data[name].push_back({ m, d, h, mm, (stat == "on-line") ? 1 : 0 });
    }

    for (auto& p : data) {
        auto rs = p.second;
        sort(rs.begin(), rs.end(), cmp);

        int size = rs.size(), tot = 0;
        for (int i = 0; i < size - 1; i++) {
            if (!rs[i].online || rs[i + 1].online) continue;

            int d1 = rs[i].day, d2 = rs[i + 1].day;
            int h1 = rs[i].h, h2 = rs[i + 1].h;
            int m1 = rs[i].m, m2 = rs[i + 1].m;
            int amount = 0, mcount = 0;

            for (int dd = d1, hh = h1, mm = m1; ;) {
                mm++;
                mcount++;
                amount += toll[hh];
                if (mm == 60) {
                    mm = 0; hh++;
                    if (hh == 24) { hh = 0; dd++; }
                }
                if (dd == d2 && hh == h2 && mm == m2) break;
            }

            if (tot == 0) {
                cout << p.first;
                printf(" %02d\n", rs[i].month);
            }

            i++; tot += amount;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", d1, h1, m1, d2, h2, m2, mcount, (amount / 100.0));
        }
        if (tot > 0) printf("Total amount: $%.2f\n", (tot / 100.0));
    }

    return 0;
}
