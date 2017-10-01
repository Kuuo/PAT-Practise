#include <cstdio>
#include <vector>
#include <algorithm>

struct stu {
    int id, de, cai;
};

bool comp(stu s1, stu s2) {
    if ((s1.de + s1.cai) != (s2.de + s2.cai)) {
        return (s1.de + s1.cai) > (s2.de + s2.cai);
    } else if (s1.de != s2.de) {
        return s1.de > s2.de;
    } else {
        return s1.id < s2.id;
    }
}

int main() {
    int N = 0, L = 0, H = 0, tot = 0;
    scanf("%d %d %d", &N, &L, &H);

    std::vector<stu> v1, v2, v3, v4;
    stu stemp;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &(stemp.id), &(stemp.de), &(stemp.cai));
        if (stemp.de >= L && stemp.cai >= L) {
            tot++;
            if (stemp.de >= H && stemp.cai >= H) {
                v1.push_back(stemp);
            } else if (stemp.de >= H && stemp.cai < H) {
                v2.push_back(stemp);
            } else if (stemp.de < H && stemp.cai < H && stemp.de >= stemp.cai) {
                v3.push_back(stemp);
            } else {
                v4.push_back(stemp);
            }
        }
    }
    std::sort(v1.begin(), v1.end(), comp);
    std::sort(v2.begin(), v2.end(), comp);
    std::sort(v3.begin(), v3.end(), comp);
    std::sort(v4.begin(), v4.end(), comp);

    printf("%d\n", tot);
    for (int i = 0; i < v1.size(); ++i)
    {
        printf("%d %d %d\n", v1[i].id, v1[i].de, v1[i].cai);
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        printf("%d %d %d\n", v2[i].id, v2[i].de, v2[i].cai);
    }
    for (int i = 0; i < v3.size(); ++i)
    {
        printf("%d %d %d\n", v3[i].id, v3[i].de, v3[i].cai);
    }
    for (int i = 0; i < v4.size(); ++i)
    {
        printf("%d %d %d\n", v4[i].id, v4[i].de, v4[i].cai);
    }

    return 0;
}
