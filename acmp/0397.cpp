/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0397 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    char mx = 'a', mn = 'z';
    for (int i = 0; s[i]; i++) mx = max(mx, s[i]), mn = min(mn, s[i]);
    int mxp = -1, mnp = -1, lbest = 10000000, pbest;
    for (int i = 0; s[i]; i++) {
        bool f = false;
        if (s[i] == mx) { f = 1; mxp = i; }
        if (s[i] == mn) { f = 1; mnp = i; }
        if (f && mxp >= 0 && mnp >= 0) {
            int l = min(mxp, mnp), r = max(mxp, mnp) + 1;
            if (r - l < lbest) { lbest = r - l; pbest = l; }
        }
    }
    cout << s.substr(pbest, lbest);
}