/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0393 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int conv(string x) {
    static map<string, int> c;
    static int last = 0;
    if (!c.count(x)) return c[x] = last++;
    return c[x];
}

int n, m, k, tms[1000], ord[1000], tmab[1000], ans[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cin >> tms[conv(s)];
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        ord[i] = conv(s);
    }
    for (int i = 0; i < k; i++) {
        cin >> tmab[i];
    }
    int j = 0, cur = 0;
    for (int i = 0; i < m; i++) {
        cur += tms[ord[i]];
        if (j < k && cur > tmab[j]) {
            cur = tmab[j];
            j++; ans[ord[i]]--;
        } else {
            ans[ord[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}