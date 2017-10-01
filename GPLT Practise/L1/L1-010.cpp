#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> num;
    int t = 0;
    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &t);
        num.emplace_back(t);
    }

    sort(num.begin(), num.end());
    printf("%d", num[0]);
    for (int i = 1; i < 3; ++i)
    {
        printf("->%d", num[i]);
    }
    return 0;
}