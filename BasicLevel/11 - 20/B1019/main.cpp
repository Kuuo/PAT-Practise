#include <bits/stdc++.h>
using namespace std;

int num;
char smax[5], smin[5];
int nmax, nmin;

int str2num(char* s) {
    int n;
    sscanf(s, "%d", &n);
    return n;
}

void setall(int n) {
    sprintf(smax, "%04d", n);
    sprintf(smin, "%04d", n);
    sort(smax, smax + 4, greater<int>());
    sort(smin, smin + 4);
    nmax = str2num(smax);
    nmin = str2num(smin);
    num = nmax - nmin;
}


int main() {
    scanf("%d", &num);

    do {
        setall(num);
        printf("%04d - %04d = %04d\n", nmax, nmin, num);
    } while (num != 6174 && num != 0);

    return 0;
}
