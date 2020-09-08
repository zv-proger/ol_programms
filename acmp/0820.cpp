/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0820 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int nxt(int a, int i, int j) {
    int dt[4];
    for (int i = 0; i < 4; i++) {
        dt[i] = (a >> (i * 4)) & 15;
    }
    dt[i] ^= 1 << j;
    dt[i] ^= 1 << (j - 1);
    dt[i] ^= 1 << (j + 1);
    if (i) dt[i-1] ^= 1 << j;
    if (i < 3) dt[i+1] ^= 1 << j;
    a = 0;
    for (int i = 3; i >= 0; i--) {
        a <<= 4;
        a |= dt[i] & 15;
    }
    return a;
}

int main() {
    int s = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c; cin >> c;
            if (c == 'b')
                s |= 1 << (i * 4 + j);
        }
    }

    int ans = 0;
    set<int> endp = {(1 << 16) - 1, 0};
    queue<int> q; q.push(s); q.push(-1);
    bool usd[1 << 16] = {0};
    usd[s] = 1;
    while(true) {
        int cr = q.front(); q.pop();
        if (cr == -1) {
            if (q.empty()) break;
            q.push(-1);
            ans ++;
            continue;
        }
        if (endp.count(cr)) {
            cout << ans; return 0;
        }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int nx = nxt(cr, i, j);
                if (usd[nx]) continue;
                usd[nx] = 1; q.push(nx);
            }
    }
    cout << "Impossible";
}