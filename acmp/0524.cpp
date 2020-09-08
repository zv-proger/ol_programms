/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0524 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int x_, y_;
bool can() {
    return (x_ > 0 && x_ < 9 && y_ > 0 && y_ < 9);
}


int calc() {
    int x, y, a, b; cin >> x >> y >> a >> b;
    if ((x+y) % 2 != (a + b) % 2) return 0;
    if (x == a && y == b) {
        return 0;
    }
    if (abs(x - a) == abs(y - b)) return 1;
    for (x_ = 1; x_ < 9; x_++) {
        for (y_ = 1; y_ < 9; y_++) {
            if (abs(x - x_) == abs(y - y_) && abs(a - x_) == abs(b - y_))
                return 2;
        }
    }
    return 0;
}

int main() {
    int c = calc();
    cout << c << endl;
    if (c > 1) {
        cout << x_ << ' ' << y_;
    }
}