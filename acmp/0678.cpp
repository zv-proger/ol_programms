/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0678 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    bool x[4] = {0, 1};
    for (auto &c : s) {
        if (c == 'A') swap(x[1], x[2]);
        if (c == 'B') swap(x[3], x[2]);
        if (c == 'C') swap(x[1], x[3]);
    }
    for (int i = 1; i < 4; i++) if (x[i]) cout << i;
}