#include <bits/stdc++.h>
using namespace std;

int k, numlegal;
double n, sum;
string num;

int islegal(string num, double& n) {
    int i = 0, size = num.size();
    int numdot = 0, numdec = 0;
    if (num[0] == '-' || num[0] == '+') {
        i = 1;
    }
    for (; i < size; ++i) {
        if (isdigit(num[i])) {
            if (numdot == 1) {
                numdec++;
                if (numdec > 2) return 0;
            }
        } else if (num[i] == '.') {
            numdot++;
            if (numdot > 1) return 0;
        } else return 0;
    }
    double t = stod(num);
    if (t < -1000 || t > 1000) return 0;
    n = t;
    numlegal++;
    return 1;
}

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        cin >> num;
        if (islegal(num, n)) sum += n;
        else cout << "ERROR: " << num << " is not a legal number\n";
    }

    printf("The average of %d number", numlegal);
    if (numlegal > 1) printf("s");
    if (numlegal > 0) printf(" is %.2f", sum / numlegal);
    else              printf("s is Undefined");

    return 0;
}
