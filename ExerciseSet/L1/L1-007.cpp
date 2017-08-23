#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char num[65536];
string pinyin[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "fu" };

int main() {
    cin >> num;
    cout << ((num[0] == '-') ? pinyin[10] : pinyin[num[0] - '0']);

    int len = strlen(num);
    for (int i = 1; i < len; ++i)
    {
        cout << " " << (pinyin[num[i] - '0']);
    }

    return 0;
}
