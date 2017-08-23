#include <bits/stdc++.h>
using namespace std;

int nums[10];

int main() {
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &nums[i]);
    }

    for (int i = 1; i < 10; ++i) {
        if (nums[i] > 0) {
            printf("%d", i);
            nums[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (nums[i] > 0) {
            for (int j = 0; j < nums[i]; ++j) {
                printf("%d", i);
            }
        }
    }

    return 0;
}
