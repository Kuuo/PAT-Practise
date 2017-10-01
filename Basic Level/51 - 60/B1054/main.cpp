#include <bits/stdc++.h>
using namespace std;

int n, numvalid;
double sum;
char input[500];

int islegal(char* in) {
    int len = strlen(in);
    char cur;
    int numdot = 0, numdecimal = 0;
    int i = (in[0] == '-' || in[0] == '+') ? 1 : 0;
    for (; i < len; ++i) {
        cur = in[i];
        if ((cur > '9' || cur < '0') && cur != '.') return 0;
        if (cur == '.') {
            if (numdot == 1) return 0;
            numdot = 1;
        } else if (numdot > 0) {
            numdecimal++;
            if (numdecimal > 2) return 0;
        }
    }

    double n = atof(in);
    if (n < -1000.0 || n > 1000.0) return 0;

    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s", &input);
        if (islegal(input)) {
            sum += atof(input);
            numvalid++;
        } else {
            printf("ERROR: %s is not a legal number\n", input);
        }
    }

    printf("The average of %d number", numvalid);
    if (numvalid) {
        if (numvalid > 1) printf("s");
        printf(" is %.2f", sum / numvalid);
    } else {
        printf("s is Undefined");
    }

    return 0;
}
