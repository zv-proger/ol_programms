/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0857 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

using ll = long long;

struct nd{
    map<ll, int> cnt;

    ll hash(const char *a) {
        ll ans = 0;
        while(*a) {
            ans = (ans * 29 + *a - 'a' + 1) % (100'000'000'000'000'000+7);
            a++;
        }
        return ans;
    }

    void add(const char *a) {
        cnt[hash(a)]++;
    }
    int count(const char *a) {
        return cnt[hash(a)];
    }
};

void zf(const char* a, vector<int> &z) {
    int n = strlen(a);
    z.assign(n, 0);
    int l, r = 0;
    for (int i = 1; a[i]; i++) {
        if (r > i) {
            z[i] = min(z[i - l], r - i);
        }
        while (a[i+z[i]] == a[z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i]; l = i;
        }
    }
}

int main() {
    FASTIO;
    nd root;
    int n; cin >> n;
    vector<int> z;
    char a[55];
    for (; n--; ) {
        cin >> a;
        int n = strlen(a);
        root.add(a);
        zf(a, z);
        for (int i = 1; i <= n; i++) {
            if (z[z.size() - i] == i) {
                root.add(a + n - i);
            }
        }
    }
    cin >> n;
    for (; n--; ) {
        cin >> a;
        cout << root.count(a) << endl;
    }
}