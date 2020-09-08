/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0764 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct comp {
    bool operator() (double a, double b) const {
        return a + 1e-9 < b;
    }
};

double ungle(int x, int y) {
    double pi = acos(-1);
    if (x == 0) return (pi / 2 + pi * (y < 0));
    return atan(1.0 * y / x) + pi * (x < 0);
}

int main() {
    int n; cin >> n;
    map<double, int, comp> dt;
    int ans = 0;
    for (; n--;) {
        int x, y; cin >> x >> y;
        ans = max(ans, ++dt[ungle(x, y)]);
    }
    cout << ans;
}