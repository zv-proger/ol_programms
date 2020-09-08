/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0598 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int cnt(int i) {
    int ans = 0;
    for (; i; i >>= 1) ans += i & 1;
    return ans;
}

int main() {
    int n; cin >> n;
    int can[15] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            can[i] |= c << j;
        }
    }
    int ans = 0, ansc = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (cnt(i) > 5) continue;
        if (cnt(i) <= ansc) continue;
        int msk = i;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                msk &= can[j];
            }
        }
        if (msk == i) {
            ansc = cnt(i);
            ans = i;
        }
    }
    int num[15], last = 1;
    for (int j = 0; j < n; j++) {
        if (ans & (1 << j)) num[j] = 1;
        else num[j] = ++last;
    }
    cout << last << endl;
    for (int i = 0; i < n; i++) {
        cout << num[i] << ' ';
    }
}