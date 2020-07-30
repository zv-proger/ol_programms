/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0736 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;



int main() {
    int n, k, l; cin >> n >> k >> l;
    vector <int> lvl(1);
    for (int t = n; t > k; t -= t/k) lvl.push_back(t/k + lvl.back());
    vector <int> dp(n+1), dpl(n+1);
    for (int i = k + 1; i <= n; i++) {
        if (i % k == 0) continue;
        dp[i] = dp[i - i/k] + i/k;
        dpl[i] = dpl[i - i/k] + 1;
    }

    for (;l--;) {
        int q, i = 0; cin >> q;
        cout << lvl[dpl[q]] + (q - dp[q]) / k << endl;
    }
}