/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0890 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct box {
    ll x1, y1, z1, x2, y2, z2;

    void read() {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if (x2 < x1) swap(x1, x2);
        if (y2 < y1) swap(y1, y2);
        if (z2 < z1) swap(z1, z2);
    }

    ll vol() const {
        return (x2 - x1) * (y2 - y1) * (z2 - z1);
    }

    box intersept(const box &oth) const {
        box a;
        a.x1 = max(x1, oth.x1); a.x2 = min(x2, oth.x2); if (a.x1 >= a.x2) a.x1 = a.x2 = 0;
        a.y1 = max(y1, oth.y1); a.y2 = min(y2, oth.y2); if (a.y1 >= a.y2) a.y1 = a.y2 = 0;
        a.z1 = max(z1, oth.z1); a.z2 = min(z2, oth.z2); if (a.z1 >= a.z2) a.z1 = a.z2 = 0;
        return a;
    }
};

int main() {
    box a, b; a.read(); b.read();
    cout << a.vol() + b.vol() - a.intersept(b).vol();
}