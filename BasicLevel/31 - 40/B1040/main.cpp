#include <bits/stdc++.h>
using namespace std;

char in[100005];
int np, npa, npat;

int main() {
    scanf("%s", &in);
    int len = strlen(in);

    for (int i = 0; i < len; i++) {
        if (in[i] == 'P') np++;
        else if (in[i] == 'A') npa += np;
        else npat = (npat + npa) % 1000000007;
    }

    printf("%d", npat);

    return 0;
}
