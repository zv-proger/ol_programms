/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0171 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    long long a; cin >> a;
    if (a == 1) { cout << 1; return 0; }
    map<int, int> q;
    for (int i = 2; i*i <= a; i++) {
        if (a % i == 0) {
            a /= i;
            q[i--]++;
        }
    }
    q[a]++;
    a = 1;
    for (auto p: q) a *= p.second + 1;
    cout << a;
}