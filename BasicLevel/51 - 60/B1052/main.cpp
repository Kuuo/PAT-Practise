#include <bits/stdc++.h>
using namespace std;

int n, c1, c2, c3, c4, c5;
vector<vector<string>> ve(3);

void sete(string& in, vector<string>& v) {
    int len = in.length();
    int p1 = 0, p2 = 1;
    string cur = "";
    while (p1 < len && p2 < len) {
        while (p1 < len && in[p1] != '[') p1++;
        p2 = p1 + 1;
        while (p2 < len && in[p2] != ']') cur += in[p2++];
        if (p2 >= len) break;
        p1 = p2 + 1;
        v.push_back(cur);
        cur = "";
    }
}

void show() {
    if (c1 > ve[0].size() || c2 > ve[1].size() || c3 > ve[2].size() ||
        c4 > ve[1].size() || c5 > ve[0].size() ||
        c1 < 1 || c2 < 1 || c3 < 1 || c4 < 1 || c5 < 1) {
        printf("Are you kidding me? @\\/@\n");
        return;
    }
    cout << ve[0][c1 - 1] << "(" << ve[1][c2 - 1] << ve[2][c3 - 1] <<
            ve[1][c4 - 1] << ")" << ve[0][c5 - 1] << endl;
}

int main() {
    string input;
    for (int i = 0; i < 3; ++i) {
        getline(cin, input);
        sete(input, ve[i]);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
        show();
    }

    return 0;
}
