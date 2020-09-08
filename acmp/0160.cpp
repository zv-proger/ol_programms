/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0160 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main() {
    int n; cin >> n;
    int dt[2][100], *pr = dt[0], *cr = dt[1], pi[100];
    bool usd[100] = {0};
    set<int> x;
    for (int i = 0; i < n; i++) {
        cin >> pi[i]; pi[i]--;
        cr[i] = i;
    }
    bool f = true;
    int t = 0;
    for (; f; ) {
        t++;
        f = false;
        swap(cr, pr);
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            f = true;
            cr[i] = pr[pi[i]];
            if (cr[i] == i) {
                x.insert(t);
                usd[i] = true;
            }
        }
    }
    int ans = 1;
    for (auto c: x)
        ans = lcm(ans, c);
    cout << ans;
}