#include <bits/stdc++.h>
using namespace std;

int n, k;
int numrow;

typedef struct info {
    string name;
    int height;
}info;

int cmp(info a, info b) {
    if (a.height == b.height) return a.name < b.name;
    return a.height > b.height;
}

vector<info> data;
deque<string> out;

void show() {
    int sz = out.size();
    for (int p = 0; p < sz; ++p) {
        if (p > 0) printf(" ");
        cout << out[p];
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    string tname;
    int theight;
    for (int i = 0; i < n; ++i) {
        cin >> tname >> theight;
        data.push_back({ tname, theight });
    }
    sort(data.begin(), data.end(), cmp);

    int ptr = 0;
    int row = n % k, i = 0;
    if (row != 0) {
        i = 1;
        row = n / k + row;
        out.push_back(data[ptr++].name);
        for (; ptr < row;) {
            if ((ptr & 1) == 1) out.push_front(data[ptr++].name);
            else out.push_back(data[ptr++].name);
        }
        show();
    }
    numrow = n / k;
    for (; i < k; ++i) {
        out.clear();
        int cur = 1;
        out.push_back(data[ptr++].name);
        while (cur < numrow) {
            if ((cur & 1) == 1) out.push_front(data[ptr++].name);
            else out.push_back(data[ptr++].name);
            cur++;
        }
        show();
    }

    return 0;
}
