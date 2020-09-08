/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0353 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

int main() {
    int dt[100000]; int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    sort (dt, dt + n);
    int bst = n - 1; double v = 0;
    for(int r = 2; r < n; r++) {
        double a = dt[r], b = dt[r-1], c = dt[r-2], p = (a + b + c) / 2;
        if (a + 1e-6 > b + c) continue;
        double sqr = sqrt(p*(p-a)*(p-b)*(p-c));
        if (v < sqr) {bst = r; v = sqr;}
    }

    if (v < 1e-20) cout << 0; else cout << fixed << setprecision(3) << v << endl;
}