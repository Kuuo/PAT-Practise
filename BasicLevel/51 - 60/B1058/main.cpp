#include <bits/stdc++.h>
using namespace std;

int stun, qusn;
int fscore[1005];

typedef struct qus {
    int id;
    int score;
    string ans;
    int errortime;
}qus;

int cmp (qus a, qus b) {
    return a.errortime > b.errortime;
}

vector<qus> allqus;

int main() {
    scanf("%d %d", &stun, &qusn);
    int cscore, cchoose, cnumans;
    string cans, tans;
    for (int i = 0; i < qusn; ++i) {
        cans = "";
        scanf("%d %d %d", &cscore, &cchoose, &cnumans);
        for (int j = 0; j < cnumans; ++j) {
            cin >> tans;
            cans += tans;
        }
        allqus.push_back({ i + 1, cscore, cans, 0 });

        // auto q = allqus[allqus.size() - 1];
        // printf("%d %d ", q.id, q.score);
        // cout << q.ans << '\n';
    }

    string cansnstr;
    int cansn;
    for (int i = 0; i < stun; ++i) {
        for (int k = 0; k < qusn; ++k) {
            cin >> cansnstr;
            cansn = atoi(cansnstr.substr(1, 1).data());
            cans = "";
            for (int j = 0; j < cansn; ++j) {
                cin >> tans;
                cans += tans;
            }
            cans.pop_back();
            if (cans == allqus[k].ans) {
                fscore[i] += allqus[k].score;
            } else {
                allqus[k].errortime++;
            }
        }
        printf("%d\n", fscore[i]);
    }

    sort(allqus.begin(), allqus.end(), cmp);
    int max = allqus[0].errortime;
    if (max == 0) {
        printf("Too simple");
    } else {
        printf("%d", max);
        for (int i = 0; i < qusn; ++i) {
            if (allqus[i].errortime == max)
                printf(" %d", allqus[i].id);
        }
    }

    return 0;
}
