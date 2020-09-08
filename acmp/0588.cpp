/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0588 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int b;
vector<int> cur, cnt;

void check() {
    if (cur == cnt) {
        for (auto &x: cur) {
            cout << x << ' ';
        }
        exit(0);
    }
}


void step(int sm, int k) {
    if (sm == 0 && k == 0) check();
    if (sm == 0 || k == 0) return;
    for (int i = 0; i < b - k; i++) {
        if (cur[i] < cnt[i]) return;
    }
    for (int i = b - k; i < b; i++) {
        if (sm < cnt[i]) return;
    }
    for (int i = 0; i < b; i++) {
        cur.push_back(i);
        cnt[(b + i - 1) % b]++;
        step(sm - i, k - 1);
        cnt[(b + i - 1) % b]--;
        cur.pop_back();
    }
}

void slow_solve() {
    cnt.resize(b);
    step(b, b);
    cout << -1;
    exit(0);
}

void fast_solve() {
    cout << 2 << ' ' << 1 << ' ';
    for (int i = 0; i < b - 7; i++) {
        cout << 0 << ' ';
    }
    cout << 1 << ' ' << 0 << ' ' << 0 <<  ' ' << 0 << ' ' << b - 4;
    exit(0);
}

int main() {

    cin >> b;
    if (b < 10) slow_solve();
    else fast_solve();
}