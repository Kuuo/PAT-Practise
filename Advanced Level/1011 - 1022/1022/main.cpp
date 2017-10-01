#include <bits/stdc++.h>
using namespace std;

int n, m;
string rawquery, query;
map<string, set<int>> mapinfo[5];

void printinfo(int type, string key) {
    int i = type - 1;
    if (mapinfo[i].find(key) == mapinfo[i].end()) {
        printf("Not Found\n");
        return;
    }

    for (auto& id : mapinfo[i][key]) printf("%07d\n", id);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        getchar();
        string info;
        for (int j = 0; j < 2; ++j) {
            getline(cin, info);
            mapinfo[j][info].insert(id);
        }
        do {
            cin >> info;
            mapinfo[2][info].insert(id);
        } while (getchar() != '\n');
        for (int j = 3; j < 5; ++j) {
            getline(cin, info);
            mapinfo[j][info].insert(id);
        }
    }

    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; ++i) {
        getline(cin, rawquery);
        int type = rawquery[0] - '0';
        query = rawquery.substr(3, rawquery.size() - 3);
        cout << rawquery << endl;
        printinfo(type, query);
    }

    return 0;
}
