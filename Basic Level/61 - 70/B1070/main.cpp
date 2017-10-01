#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<double, vector<double>, greater<double>> que;

int main() {
    scanf("%d", &n);
    int input;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input);
        que.push(input * 1.0);
    }

    double a, b;
    while (que.size() > 1) {
        a = que.top();
        que.pop();
        b = que.top();
        que.pop();
        que.push((a + b) / 2.0);
    }

    printf("%d", (int)que.top());

    return 0;
}
