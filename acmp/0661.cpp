/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0661 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()


using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e18 + 7;

#define f first
#define s second
#define bi f.f
#define ei f.s
#define si s

int n, b, e;
pair<pii, int> dt[100000];
int xx[200002], c = 0;

#define pb(x) xx[c++] = x;

void read() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> n >> b >> e;
    pb(b); pb(e);
    for (int i = 0; i < n; i++) { auto &t = dt[i]; cin >> t.bi >> t.ei >> t.si; pb(t.bi); pb(t.ei); }
    sort(xx, xx + c);
    int l = 0;
    for (int i = 0; i < c; i++, l++) {
        swap(xx[i], xx[l]);
        if (l && xx[l] == xx[l-1]) l--;
    }
    c = l;
}

int main() {
    read();
    sort(dt, dt + n);
    ll prev, cur = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> st;
    int q = 0;
    for (int i = 0;  i < c && xx[i] <= e; i++) {
        swap(prev, cur);
        while (q < n && dt[q].bi == xx[i]) {
            st.push({prev + dt[q].si, dt[q].ei});
            q++;
        }
        while (!st.empty() && st.top().s <= xx[i] && st.top().s != e) {
            st.pop();
        }
        cur = xx[i] < b ? 0 : st.top().f;
    }
    cout << cur << endl;
}