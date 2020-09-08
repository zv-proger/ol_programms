/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0984 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    int p, n, k; cin >> p >> n >> k;
    vector<string> dt;
    string s; getline(cin, s);
    for (int i = 0; i < p; i++) {
        getline(cin, s); dt.push_back(s);
    }
    vector<int> ord(p);
    for (auto &x: ord) cin >> x;
    map<string, int> cnt;
    for (int i = 0; i < p; i++) {
        if (cnt[dt[i]]++ < k) {
            n--;
            cout << dt[i] << " #" << ord[i] << endl;
        }
        if (!n) return;
    }
}

int main() {
    FASTIO;
    solve();
}