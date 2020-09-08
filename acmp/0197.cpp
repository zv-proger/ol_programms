/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0197 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator+ (pii a, pii b) {return {a.f + b.f, a.s + b.s}; }

int n, dt[102][102];

bool check(pii x) {
    return x.f > 0 && x.f <= n && x.s > 0 && x.s <=n;
}

int main() {
    vector<pii> sts;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        sts.push_back(i % 2? pii(1, i): pii(i, 1));
    }
    pii cur = {1, -1}, prev = {-1, 1};
    int val = 0;
    for (auto st: sts) {
        while (st.f && st.s) {
            if (check(st)) dt[st.f][st.s] = ++val;
            st = st + cur;
        }
        swap(cur, prev);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", dt[i][j]);
        }
        cout << endl;
    }
}