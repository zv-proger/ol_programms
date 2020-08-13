/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0824 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

using ll = __int128_t;
ll md = 1e18 + 7;
ll seek = 127;

ll powmd(ll x, ll n) {
    if (n == 1) return x;
    if (n & 1) return x*powmd(x*x%md, n/2)%md;
    return powmd(x*x%md, n/2);
}

ll rev(ll x) {
    return powmd(x, md-1);
}

char a[100001], b[200001] = {0};
ll sk[200001] = {1}, ha[100001], hb[200001];

int main() {
    FASTIO;
    cin >> a >> b;
    ha[0] = a[0]; hb[0] = b[0];
    int n = strlen(a), m = strlen(b), mm = m * 2 - 1;
    for (int i = m; i < mm; i++) b[i] = b[i-m];
    for (int i = 1; i < max(mm, n); i++) {
        sk[i] = sk[i-1] * seek % md;
    }
 
    map<ll, int> cnt;
    if (m == 1) cnt[*ha]++;
    for (int i = 1; i < n; i++) {
        ha[i] = (sk[i] * a[i] + ha[i-1]) % md;
        if (i == m - 1) cnt[ha[i]]++;
        if (i >= m) cnt[(ha[i]+md-ha[i-m])%md*rev(sk[i-m+1])%md]++;
    }
    long long ans = m == 1? cnt[*hb]: 0;
    for (int i = 1; i < mm; i++) {
        hb[i] = (sk[i] * b[i] + hb[i-1]) % md;
        if (i == m - 1) {
            if (!cnt.count(hb[i])) continue;
            ans += cnt[hb[i]]; 
            cnt.erase(hb[i]);
        }
        if (i >= m) {
            if (!cnt.count((hb[i]+md-hb[i-m])%md*rev(sk[i-m+1])%md)) continue;
            ans += cnt[(hb[i]+md-hb[i-m])%md*rev(sk[i-m+1])%md];
            cnt.erase((hb[i]+md-hb[i-m])%md*rev(sk[i-m+1])%md);
        }
    }
    cout << ans << endl;
}