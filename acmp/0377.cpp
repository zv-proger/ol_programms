/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0377 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<pii> points;
    for (; n--;) {
        int a, b; cin >> a >> b;
        points.push_back({a, 1});
        points.push_back({b, -1});
    }
    sort(ALL(points));
    int st = 0, ans = 0, pr;
    for (auto &p : points) {
        if (st) {
            ans += p.first - pr;
        }
        st += p.second;
        pr = p.first;
    }
    cout << ans << endl;
}