/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0659 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int x[25], n, k;
int ans, ans_msk;


void step(int msk) {
    for (msk = 0; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == k) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                s += msk & (1 << i) ? __builtin_popcount(msk & x[i]): __builtin_popcount((msk^((1 << n) - 1)) & x[i]);
            }
            if (s > ans) {
                ans_msk = msk;
                ans = s;
            }
        }
    }
}

int main() {
    int m; cin >> n >> k >> m;
    while (m--) {
        int a, b; cin >> a >> b; a--, b--;
        if (a == b) continue;
        x[a] |= 1 << b;
        x[b] |= 1 << a;
    }
    step(0);
    for (int i = 0; i < n; i++) {
        if (ans_msk & (1 << i)) cout << i + 1 << ' ';
    }
}