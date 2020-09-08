/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0769 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct nd {
    map<char, nd* > nxt;
    void add(char *s) {
        if (!*s) return;
        if (!nxt.count(*s)) { nxt[*s] = new nd; }
        nxt[*s] -> add(s + 1);
    }
    int cnt() {
        if (nxt.empty()) return 1;
        int ans = 0;
        for (auto &p: nxt) {
            ans += p.second -> cnt();
        }
        return ans;
    }
};

int main() {
    nd root; int n; cin >> n;
    char a[21];
    for (gets(a); n--;) {
        root.add(gets(a));
    }
    cout << root.cnt();
}