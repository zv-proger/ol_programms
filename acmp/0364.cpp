/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0364 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

using ull = unsigned long long;

bool check(ull x) {
    ull sum = x != 1, j;
    for (j = 2; j * j < x; j++) {
        if (x % j == 0) {
            sum += j + x / j;
        }
    }
    sum += j*j == x ? j : 0;
    return x == sum;
}

void slow_solve(ull n, ull m) {
    bool f = false;
    for (ull i = n; i <= m; i++) {
        if (check(i)) {
            cout << i << ' ';
            f = true;
        }
    }
    if (!f) {
        cout << "Absent" << endl;
    }
}

void fast_solve(ull n, ull m) {
    vector<ull> ans= {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128,};
    if (ans.empty())
        for (ull i = 2; i < 33; i++) {
            ull x = ((1ULL << i) - 1) * (1ULL << (i - 1));
            if (x > m) break;
            if (check(x)) ans.push_back(x);
        }
    bool f = false;
    for (auto x: ans) {
        if (x >= n && x <= m) {
            f = true;
            cout << x << ' ';
        }
    }
    if (!f) {
        cout << "Absent" << endl;
    }
}

int main() {
    ull n, m; cin >> n >> m;
    fast_solve(n, m);
}