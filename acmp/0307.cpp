/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0307 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int MXN = 251;
int fen[MXN][MXN];

void inc(int x, int y) {
    for (int i = x; i < MXN; i |= i + 1) {
        for (int j = y; j < MXN; j |= j + 1) {
            fen[i][j]++;
        }
    }
}

int calc(int x, int y) {
    int ans = 0;
    for (int i = x; i >= 0; i = (i & i + 1) - 1) {
        for (int j = y; j >= 0; j = (j & j + 1) - 1) {
            ans += fen[i][j];
        }
    }
    return ans;
}

int main() {
    int n; cin >> n >> n >> n;
    long long ans = 0;
    for (; n--; ) {
        int a, b; cin >> a >> b;
        inc(a, b);
        ans += calc(250, b - 1) - calc(a, b - 1);
        ans += calc(a - 1, 250) - calc(a - 1, b);
    }
    cout << ans << endl;
}