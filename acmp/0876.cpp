/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0876 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    double a, b, r; cin >> a >> b >> r;
    double best = -1e21, bx, by;
    for (double x = -r + 1e-6; x < r - 1e-6; x += 1e-6) {
        double y = sqrt(r*r - x*x);
        if (a*x + b*y > best) { best = a*x + b*y; bx = x; by = y; }
        y = -y;
        if (a*x + b*y > best) { best = a*x + b*y; bx = x; by = y; }
    }
    cout << fixed << setprecision(5) << best << endl << bx << ' ' << by;
}