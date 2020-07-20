/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0065 с сайта acmp.ru
*/

const int inf = 1e9;

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<int> ans;
    int best = inf;
    for (int i = 1; i <= n; i++) {
        string p; cin >> p;
        int cur = 0;
        for(int j = 0; s[j]; j++) {
            cur += s[j] != p[j];
        }
        if (cur < best) { ans.clear(); best = cur; }
        if (cur == best) { ans.push_back(i); }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << ' ';
}