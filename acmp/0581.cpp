/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0581 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

struct line{
    double a, b, c;
    line(pii f, pii s) {
        a = s.y - f.y;
        b = f.x - s.x;
        c = sqrt(a * a + b * b);
        a /= c; b /= c;
        c = - a * f.x - b * f.y;
    }
    double dist(pii x) {
        return abs(x.x * a + x.y * b + c);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c >> d;
    line l({a, b}, {c, d});
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x, y, r; cin >> x >> y >> r;
        if (l.dist({x, y}) + 1e-3 < r) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (auto &x: ans) cout << x << ' ';
}