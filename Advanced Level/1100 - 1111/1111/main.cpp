#include <bits/stdc++.h>
using namespace std;
#define INF 999999

int n, m, source, target;
int dist[500][500], tcst[500][500];
int mindist = INF, mintime = INF;
vector<int> mindistpath, mintimepath;

void printv(vector<int>& v) {
    for (auto& x : v) printf(" -> %d", x);
}

void setpath(vector<int>& pre, vector<int>& v) {
    int t = target;
    while (pre[t] != -1) {
        v.push_back(t);
        t = pre[t];
    }
    reverse(v.begin(), v.end());
}

void dijdist(int s) {
    vector<int> dis(n, INF), tim(n, INF), visited(n, 0), pre(n, -1);
    dis[s] = tim[s] = 0;

    while (true) {
        int u = -1, mind = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dis[i] < mind) {
                mind = dis[i];
                u = i;
            }
        }
        if (u == -1) {
            mindist = dis[target];
            setpath(pre, mindistpath);
            break;
        }
        visited[u] = 1;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || dist[u][i] == 0) continue;
            if ((dis[i] > dis[u] + dist[u][i]) ||
                (dis[i] == dis[u] + dist[u][i] && tim[i] > tim[u] + tcst[u][i])) {
                dis[i] = dis[u] + dist[u][i];
                tim[i] = tim[u] + tcst[u][i];
                pre[i] = u;
            }
        }
    }
}

void dijtime(int s) {
    vector<int> cnt(n, INF), tim(n, INF), visited(n, 0), pre(n, -1);
    cnt[s] = tim[s] = 0;

    while (true) {
        int u = -1, mind = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && tim[i] < mind) {
                mind = tim[i];
                u = i;
            }
        }
        if (u == -1) {
            mintime = tim[target];
            setpath(pre, mintimepath);
            break;
        }
        visited[u] = 1;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || tcst[u][i] == 0) continue;
            if ((tim[i] > tim[u] + tcst[u][i]) ||
                (tim[i] == tim[u] + tcst[u][i] && cnt[i] > cnt[u] + 1)) {
                tim[i] = tim[u] + tcst[u][i];
                cnt[i] = cnt[u] + 1;
                pre[i] = u;
            }
        }
    }
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int from, to, oneway, len, timecost;
        scanf("%d %d %d %d %d", &from, &to, &oneway, &len, &timecost);
        dist[from][to] = len;
        tcst[from][to] = timecost;
        if (!oneway) {
            dist[to][from] = len;
            tcst[to][from] = timecost;
        }
    }
    scanf("%d %d", &source, &target);

    dijdist(source);
    dijtime(source);

    printf("Distance = %d", mindist);
    if (mindistpath == mintimepath) {
        printf("; Time = %d: %d", mintime, source);
        printv(mindistpath);
    } else {
        printf(": %d", source);
        printv(mindistpath);
        printf("\nTime = %d: %d", mintime, source);
        printv(mintimepath);
    }

    return 0;
}
