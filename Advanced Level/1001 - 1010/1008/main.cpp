#include <cstdio>
using namespace std;

int n, prev, next;
int ret;

int main() {
    scanf("%d", &n);
    ret = n * 5;
    scanf("%d", &prev);
    ret += prev * 6;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &next);
        if (next > prev) ret += 6 * (next - prev);
        else ret += 4 * (prev - next);
        prev = next;
    }

    printf("%d", ret);
    return 0;
}
