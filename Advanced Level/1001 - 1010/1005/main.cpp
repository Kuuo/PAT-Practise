#include <bits/stdc++.h>
using namespace std;

int sum;
string input;
string en[] = { "zero", "one", "two", "three", "four",
              "five", "six", "seven", "eight", "nine" };

int main() {
    cin >> input;

    for (int i = 0; i < input.length(); ++i) {
        sum += input[i] - '0';
    }

    string strsum = to_string(sum);
    for (int i = 0; i < strsum.length(); ++i) {
        if (i != 0) cout << " ";
        cout << en[strsum[i] - '0'];
    }

    return 0;
}
