/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0563 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int ans, dt[100000];

void calc(int s, int e, int i) {
    if (s == e) return;
    if (s == e - 1) return;
    if (i == 32) { int a = e - s; if ((a * (a - 1) / 2) % 2) { ans ^= -1; } return;}
    int l = s, r = e;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (dt[m] & (1 << i)) r = m;
        else l = m;
    }
    if ((dt[l] & (1 << i))) r = l;
    int a = r - s, b = e - r;
    if ((a * b) & 1) {
        ans ^= (1 << i) - 1;
    }
    calc(s, r, i + 1); calc(r, e, i + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    assert(n <= 100000);
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
        ans ^= dt[i];
    }
    sort(dt, dt + n, [] (int a, int b) {
        for (int i = 0; i < 32; i++) {
            if ((a & (1 << i)) && !(b & (1 << i))) return false;
            if ((b & (1 << i)) && !(a & (1 << i))) return true;
        }
        return false;
    });

    calc(0, n, 0);
    cout << ans;
}