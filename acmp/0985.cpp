/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0985 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

string a[3];

void doans(string a) { cout << a; exit(0); }

void check(char c, string msg) {
    if (a[0][0] == c) {
        if (a[1][0] == c && a[2][0] == c) doans(msg);
        if (a[1][1] == c && a[2][2] == c) doans(msg);
        if (a[0][1] == c && a[0][2] == c) doans(msg);
    }

    if (a[0][2] == c) {
        if (a[1][2] == c && a[2][2] == c) doans(msg);
        if (a[1][1] == c && a[2][0] == c) doans(msg);
    }

    if (a[2][0] == c)
        if (a[2][1] == c && a[2][2] == c) doans(msg);

    if (a[1][1] == c) {
        if (a[0][1] == c && a[2][1] == c) doans(msg);
        if (a[1][0] == c && a[1][2] == c) doans(msg);
    }
}

int main() {
    cin >> a[0] >> a[1] >> a[2];
    check(88, "Win");
    check(79, "Lose");
    cout << "Draw";
}