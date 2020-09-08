/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0897 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b): a;
}

bool check(int x) {
    if (x < 2) return false;
    map<int, int> muls;
    for (int i = 2; i * i <= x || x == i; i++) {
        if (x % i == 0) {
            x /= i;
            muls[i--]++;
        }
    }
    if (x > 1) return false;
    int a = muls.begin() -> second;
    for (auto &p: muls) {
        a = gcd(a, p.second);
    }
    return a > 1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << (check(x)?"YES":"NO") << endl;
    }
}