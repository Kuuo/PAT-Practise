#include <bits/stdc++.h>
using namespace std;

int n;
string m1[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string m2[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int getnum(string mar) {
    for (int i = 0; i < 12; ++i) {
        if (m2[i] == mar) return (i + 1) * 13;
    }
    for (int i = 0; i <= 12; ++i) {
        if (m1[i] == mar) return i;
    }
    return -1;
}

string tomars(int n) {
    if (n < 13) return m1[n];
    int r = n % 13;
    if (r == 0) return m2[n / 13 - 1];
    return m2[n / 13 - 1] + " " + m1[r];
}

int toearths(string s) {
    if (s.size() > 4) {
        stringstream ss(s);
        string high, low;
        ss >> high >> low;
        return getnum(high) + getnum(low);
    }
    return getnum(s);
}

int main() {
    scanf("%d", &n);
    getchar();
    string input;
    for (int i = 0; i < n; ++i) {
        getline(cin, input);
        if (isdigit(input[0])) {
            cout << tomars(stoi(input)) << endl;
        } else {
            cout << toearths(input) << endl;
        }
    }

    return 0;
}
