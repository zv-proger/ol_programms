/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0889 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
using pii = pair<int, int>;

int main() {
    int cur, m; cin >> cur >> m;
    priority_queue<pii> q;
    for (; m--; ) {
        int p, h; cin >> p >> h;
        q.push({h, p});
    }
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (p == cur) cur++;
        else if (p == cur - 1) cur--;
    }
    cout << cur;
}