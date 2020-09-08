/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0443 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int m, x;

int hsh(const string &a) {
    int ml = 1, ans = 0;
    for (auto &c: a) {
        ans = (ans + (c - '0') * ml) % m;
        ml = (ml * x) % m;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n >> m >> x;
    int ans = 0; map<int, int> dt;
    for (; n--; ) {
        string s; cin >> s;
        ans += dt[hsh(s)]++;
    }
    cout << ans;
}