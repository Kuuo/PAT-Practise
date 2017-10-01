#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

char num[1001];

int main() {

    cin >> num;

    map<int, int> ret;

    int len = strlen(num);
    for(int i = 0; i < len; i++) {
        ret[num[i] - '0']++;
    }

    for(auto e : ret) {
        printf("%d:%d\n", e.first, e.second);
    }

    return 0;
}
