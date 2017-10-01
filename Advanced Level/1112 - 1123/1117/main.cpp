#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> miles;

int main() {
    scanf("%d", &n);
    miles.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &miles[i]);

    sort(miles.begin(), miles.end(), greater<int>());

    if (miles[0] == 0) {
        printf("0");
        return 0;
    }

    int e = 0;
    while (e < n && miles[e] > e + 1) e++;

    printf("%d", e);
    return 0;
}
