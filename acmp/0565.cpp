/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0565 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r; cin >> n >> r;
    r--;
    vector<pair<pii, int>> dt;
    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if (b < a) dt.push_back({{b, a}, i});
    }
    sort(dt.begin(), dt.end());
    int cr = 0;
    for (auto &p: dt) {
        if (!r) { cout << "Impossible"; return 0; }
        int a = p.first.second;
        int b = p.first.first;
        ans.push_back({cr, p.second});
        cr += (a - b + r - 1) / r;
        if (b < cr) {
            cout << "Impossible"; return 0;
        }
    }
    for (auto &p: ans) {
        cout << p.first << ' ' << p.second << endl;
    }
}