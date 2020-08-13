/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0964 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

map<int, set<string>> dt;

void print_prefix() {
    static bool inited = false;
    if (!inited) { inited = true; return; }
    cout << "=====" << endl;
}

int hsh(const string &a) {
    int ans = 0, md = 1e7+7, sk = 301;
    for (auto &c: a) ans = (ans * sk + c) % md;
    return ans;
}

void request_add() {
    string kw, st; cin >> kw >> kw >> st >> st;
    cout << (dt[hsh(kw)].count(st)? "Already exists": "OK") << endl;
    dt[hsh(kw)].insert(st);
}

void request_rm() {
    string kw, st; cin >> kw >> kw >> st >> st;
    cout << (dt[hsh(kw)].count(st)? "OK": "Not found") << endl;
    dt[hsh(kw)].erase(st);
}

void request_search() {
    string kw; cin >> kw;
    auto &sts = dt[hsh(kw)];
    cout << "Results: " << sts.size() << " site(s) found" << endl;
    auto ptr = sts.begin();
    for (int i = 1; i <= 10; i++) {
        if (ptr == sts.end()) break;
        cout << i << ") " << *ptr << endl;
        ptr++;
    }
}

void request() {
    print_prefix();
    string s; cin >> s;
    if      (s == "Add")    request_add();
    else if (s == "Remove") request_rm();
    else if (s == "Search") request_search();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        request();
    }
}