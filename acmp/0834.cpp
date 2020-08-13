/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0834 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define sq(x) ((x)*(x))

int main() {
    double x, y, x1, y1; cin >> x >> y >> x1 >> y1;
    double r; cin >> r;
    double d = sqrt(sq(x - x1) + sq(y - y1));
    double pi = acos(-1);
    double s;
    if (r > d) s = pi * sq(r);
    else s = (pi - acos(r / d)) * sq(r) + r * sqrt(sq(d) - sq(r));
    cout << fixed << setprecision(3) << s;

}