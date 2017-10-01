#include <bits/stdc++.h>
using namespace std;

char in[105][20];
int valid[105];
int n, numvalid;
int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char M[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

int isvalid(char* id) {
    int Z = 0;
    for (int i = 0; i < 17; ++i) {
        if (!isdigit(id[i])) return 0;
        Z += (id[i] - '0') * weight[i];
    }
    Z %= 11;
    return id[17] == M[Z];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &in[i]);
        if (isvalid(in[i])) {
            valid[i] = 1;
            numvalid++;
        }
    }

    if (numvalid == n) {
        printf("All passed");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (!valid[i]) printf("%s\n", in[i]);
    }

    return 0;
}
