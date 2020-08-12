/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0175 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<vector<int>> usds = {
    {0, 1, 2, 3, 4, 5}, //0
    {1, 2}, //1
    {0, 1, 6, 4, 3}, //2
    {0, 1, 2, 3, 6}, //3
    {1, 2, 5, 6}, //4
    {0, 5, 6, 2, 3}, //5
    {0, 5, 6, 2, 3, 4}, //6
    {0, 1, 2}, //7
    {0, 1, 2, 3, 4, 5, 6}, //8
    {0, 1, 2, 3, 5, 6}, //9
};

vector<vector<int>> nusds = {
    {6}, //0
    {0, 3, 4, 5, 6}, //1
    {2, 5}, //2
    {4, 5}, //3
    {0, 3, 4}, //4
    {1, 4}, //5
    {1}, //6
    {3, 4, 5, 6}, //7
    {}, //8
    {4}, //9
    {0, 1, 2, 3, 4, 5, 6}, //10
};

set<pii> need = {
    {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 6},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6},
    {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6},
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}
}, noneed = need;

int main() {
    char a, b, c, d; cin >> a >> b >> c >> c >> d;
    a -= '0'; b -= '0'; c -= '0'; d -= '0';
    int ans = -1;
    while (!need.empty() || !noneed.empty()) {
        for (auto el: usds[d]) need.erase({0, el});
        for (auto el: usds[c]) need.erase({1, el});
        for (auto el: usds[b]) need.erase({2, el});
        if (a) for (auto el: usds[a]) need.erase({3, el});
        for (auto el: nusds[d]) noneed.erase({0, el});
        for (auto el: nusds[c]) noneed.erase({1, el});
        for (auto el: nusds[b]) noneed.erase({2, el});
        for (auto el: nusds[a ? a : 10]) noneed.erase({3, el});
        if ((a * 10+b) == 23 && (c * 10 + d) == 59) a = b = c = d = 0;
        else { d++; c += d / 10; b += c / 6; a += b / 10; d %= 10; c %= 6; b %= 10; }
        ans++;
    }
    cout << ans << endl;
}