/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0875 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator +(const pii &a, const pii &b) { return {a.f + b.f, a.s + b.s}; }

bool dt[2][100][100], (*cr)[100] = dt[0], (*pr)[100] = dt[1];
int n, m;

bool &get(bool (*x)[100], const pii &pos) {
    int i = pos.f, j = pos.s;
    i = (i + n) % n; j = (j + m) % m;
    return x[i][j];
}

int count(bool (*t)[100], const pii &pos) {
    pii sk[] = {{0, 1}, {1, 1}, {1, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 1}};
    int ans = 0;
    for (auto &x: sk) {
        ans += get(t, pos + x);
    }
    return ans;
}

int main() {
    int t; cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            cr[i][j] = c == '*';
        }
    } 
    for (; t >= 0; t--) {
        swap(cr, pr);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = count(pr, {i, j});
                cr[i][j] = pr[i][j];
                if (!t) cout << (cr[i][j]? '*': '.');
                if (c < 2 || c > 3) cr[i][j] = 0;
                if (c == 3) cr[i][j] = 1;sdf
            }
            if (!t) cout << endl;
        }
    }
}