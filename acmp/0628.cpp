/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0628 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define vec pair<double, double>
#define x first
#define y second
vec readVec() {;
    vec a; cin >> a.x >> a.y;
    return a;
}
#define sq(x) ((x)*(x))
double dist(const vec &a, const vec &b) {
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vec> dt(n);
    for (auto &x: dt) x = readVec();
    double l = min(dt[0].x, dt[1].x), r = max(dt[0].x, dt[1].x);
    while (r - l > 1) {
        double ml = l + (r - l) / 3, mr = l + 2 * (r - l) / 3;
        double sl = 0, sr = 0;
        for (auto &x: dt) {
            sl += dist(x, {ml, 0});
            sr += dist(x, {mr, 0});
        }
        if (sl > sr) {
            l = ml;
        } else {
            r = mr;
        }
    }
    cout << fixed << setprecision(3) << l;
}