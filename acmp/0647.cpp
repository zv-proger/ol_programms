/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0647 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int MX_N = 65535 * 2;
int fen[MX_N] = {0};

void inc_fen(int x, int c = 1) {
    for(; x <= MX_N; x |= x + 1)
        fen[x] += c;
}
int calc_fen(int x) {
    int ans = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        ans += fen[x];
    return ans;
}

int last_fen = 65535 * 2, last[65536];

int main() {
    int n, m; cin >> n >> m;

    for (int i = n; i > 0; i--) {
        last[i] = --last_fen;
        inc_fen(last[i]);
    }
    for (; m--; ) {
        int x; cin >> x;
        cout << calc_fen(last[x]) << ' ';
        inc_fen(last[x], -1);
        last[x] = --last_fen;
        inc_fen(last[x]);
    }
}