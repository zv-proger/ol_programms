/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0386 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int dlt = 80;

int main()
{
    int n; cin >> n;
    cout << "YES" << endl;
    int dx = 0, dy = dlt, x = -9999, y = 0, t = 0;
    while (n--) {
        cout << x << ' ' << y << endl;
        x += dx, y += dy;
        switch(t) {
            case 7:
            case 0: dx++; break;
            case 1:
            case 2: dy--; break;
            case 3:
            case 4: dx--; break;
            case 5:
            case 6: dy++; break;
        }
        if (abs(dx) == abs(dy) || abs(dx) + abs(dy) == dlt) t++;
    }
}
