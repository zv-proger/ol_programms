/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0917 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
    int n; cin >> n;
    double l = 0, r = 1e8;
    vector<double> blks(n);
    for (auto &x: blks) {
        cin >> x;
        l = max(l, x / 2);
    }
    double angle;
    while (r - l > 1e-8) {
        double m = (r + l) / 2;
        angle = 0;
        for (auto &x: blks) {
            angle += asin(x / m / 2);
        }
        if (angle > pi) {
            l = m;
        } else {
            r = m;
        }
    }
#define sq(x) ((x)*(x))
    if (abs(angle - pi) < 1e-9) {
        double ans = 0;
        for (auto &x: blks) {
            ans += x * sqrt(abs(sq(l) - sq(x / 2))) / 2;
        }
        cout << fixed << setprecision(3) << ans;
        return 0 ;
    }
    sort(blks.begin(), blks.end());
    double mx = blks.back(); blks.pop_back();
    r = 1e7; l = mx / 2;
    while (r - l > 1e-8) {
        double m = (r + l) / 2;
        angle = 0;
        for (auto &x: blks) {
            angle += asin(x / m / 2);
        }
        if (angle > asin(mx / m / 2)) {
            r = m;
        } else {
            l = m;
        }
    }
    double ans = 0;
    for (auto &x: blks) {
        ans += x * sqrt(abs(sq(l) - sq(x / 2))) / 2;
    }
    ans -= mx * sqrt(abs(sq(l) - sq(mx / 2))) / 2;
    cout << fixed << setprecision(3) << ans;
}