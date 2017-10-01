#include <bits/stdc++.h>
using namespace std;

typedef struct stu {
    string name;
    int h;
} stu;

int cmp(stu a, stu b) {
    if (a.h != b.h) return a.h > b.h;
    return a.name < b.name;
}

int n, k;
vector<stu> data;

void fun(int index, int n) {
    deque<string> que;
    int k = 1;
    for (int i = index; i < index + n; i++) {
        if ((k & 1) == 1) {
            que.push_back(data[i].name);
        } else {
            que.push_front(data[i].name);
        }
        k++;
    }
    k = 0;
    for (auto& s : que) {
        if (k == 1) printf(" ");
        k = 1;
        cout << s;
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        string tname; int th;
        cin >> tname >> th;
        data.push_back({ tname, th });
    }
    sort(data.begin(), data.end(), cmp);

    int numrow = n / k;
    int r = n % k;
    fun(0, numrow + r);
    int i = numrow + r;
    while (i < n) {
        fun(i, numrow);
        i += numrow;
    }

    return 0;
}
