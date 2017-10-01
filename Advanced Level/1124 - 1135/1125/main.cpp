#include <bits/stdc++.h>
using namespace std;

int n, input;
priority_queue<double, vector<double>, greater<double>> que;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input);
        que.push(input);
    }

    while (que.size() > 1) {
        double a = que.top(); que.pop();
        double b = que.top(); que.pop();
        que.push((a + b) / 2);
    }

    printf("%d", (int)que.top());

    return 0;
}
