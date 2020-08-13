/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0836 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

bool f(int x) {
    if (x & 1) return 0;
    return x / 64 % 2;
}

int main() {
    FASTIO;
    int n; cin >> n;
    vector<int> ans;
    for (; n--;) {
        int x; cin >> x;
        if (f(x)) ans.push_back(x);
    }

    sort(ALL(ans));
    cout << ans.size() << endl;
    for(auto v: ans) cout << v << ' ';
}