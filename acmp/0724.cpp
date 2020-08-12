/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0724 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int n, st[20];
int ans = -1, cur;

int count(unsigned a) {
    int xx = 0; for (; a; a /= 2) xx += a & 1;
    return xx;
}

void step(int z, int i) {
    if (!z) {
        if (count(ans) > count(cur)) ans = cur;
        return;
    }
    if (i == n) return;
    step(z, i + 1);
    cur ^= 1 << i;
    step(z & st[i], i + 1);
    cur ^= 1 << i;
}

int main() {
    int m; cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            st[j] <<= 1; st[j] |= c;
        }
    }
    step((1 << m) - 1, 0);
    if (ans == -1) {
        cout << "Impossible";
    } else {
        cout << count(ans) << endl;
        for (int i = 0; i < n; i++) {
            if (ans & (1 << i)) cout << i+1 << ' ';
        }
    }
}