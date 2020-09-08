/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0896 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b): a; }

int main() {
    int n, m; cin >> n >> m;
    int lcd = n * m;
    set<int> x;
    int a = 0, b = 0;
    while(a < lcd) {
        x.insert(a); a += n;
    }
    while(b < lcd) {
        x.insert(b); b += m;
    }
    auto y = x;
    if (lcd & 2 == 0)
        for (auto &c: y) {
            if (c > lcd / 2) break;
            x.erase(c + lcd / 2);
        }
    cout << x.size();
}