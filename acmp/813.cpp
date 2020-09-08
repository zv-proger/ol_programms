/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 813 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

string expr;
vector<size_t> sign_ps;


ll calc(int l, int r) {
    ll st = 0, s = 1, ans = 0, sb = 0;
    bool f = true;
    for (int i = l; i < r; i++) f &= isdigit(expr[i]);
    if (f) { istringstream(expr.substr(l, r - l)) >> ans; return ans; }
    for (int i = l; i < r; i++) {
        char c = expr[i];
        switch(c) {
          case '+':
          case '-':
          case '*':
            if (!st) {
                if (!s) ans *= calc(l, i);
                else ans += calc(l, i) * s;
                l = i + 1; s = (c == '+') - (c == '-');
            } break;
          case '(': st++; break;
          case ')': st--; break;
        }
        sb += !st;
    }
    if (sb == 1) return calc(l + 1, r - 1);
    if (!s) ans *= calc(l, r);
    else ans += calc(l, r) * s;
    return ans;
}

void step(size_t i = 0) {
    if (i == sign_ps.size()) {
        if (24 == calc(0, expr.size())) {
            cout << "YES";
            exit(0);
        }
        return;
    }
    expr[sign_ps[i]] = '+'; step(i + 1);
    expr[sign_ps[i]] = '-'; step(i + 1);
    expr[sign_ps[i]] = '*'; step(i + 1);
}

void init_step() {
    sign_ps.clear();
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ' ') sign_ps.push_back(i);
    }
}

vector<char*> x = {
    "%i (%i %i) %i",
    "(%i %i) (%i %i)",
    "((%i %i) %i) %i",
    "(%i (%i %i)) %i",
    "%i (%i (%i %i))",
    "%i ((%i %i) %i)",
    "0-%i (%i %i) %i",
    "(0-%i %i) (%i %i)",
    "((0-%i %i) %i) %i",
    "(0-%i (%i %i)) %i",
    "0-%i (%i (%i %i))",
    "0-%i ((%i %i) %i)",
};

int main() {
    char bf[1000];
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (auto s: x) {
        sprintf(bf, s, a, b, c, d);
        expr = bf;
        init_step(); step();
    }

    cout << "NO";
}