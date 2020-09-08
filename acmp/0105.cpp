/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 105 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll lval;
string expr;
vector<size_t> sign_ps;

void trim(string &s) {
    while (!s.empty() && isspace(s.front())) s.erase(0, 1);
    while (!s.empty() && isspace(s.back())) s.pop_back();
}

void read() {
    string s; getline(cin, s);
    for (auto &c: s) assert(c != '-');
    istringstream ss(s);
    char c; ss >> lval >> c;
    getline(ss, expr); trim(expr);
    for (int i = 1; expr[i]; i++) {
        if (isspace(expr[i]) && isspace(expr[i-1])) { expr.erase(--i, 1); continue; }
        if (expr[i] == ')' && isspace(expr[i-1])) { expr.erase(--i, 1); continue; }
        if (isspace(expr[i]) && expr[i-1] == '(') { expr.erase(i--, 1); continue; }
        if (expr[i] == '(' && isdigit(expr[i-1])) { expr.insert(i, 1, ' '); continue; }
        if (expr[i-1] == ')' && isdigit(expr[i])) { expr.insert(i, 1, ' '); continue; }
        if (expr[i-1] == ')' && expr[i] == '(') { expr.insert(i, 1, ' '); continue; }
    }
    for (auto &c: expr) if (isspace(c)) c = ' ';
    while (expr.find("( (") != string::npos) expr.erase(expr.find("( (") + 1, 1);
    while (expr.find(") )") != string::npos) expr.erase(expr.find(") )") + 1, 1);
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ' ') sign_ps.push_back(i);
    }
}

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
        if (lval == calc(0, expr.size())) {
            cout << lval << '=' << expr;
            exit(0);
        }
        return;
    }
    expr[sign_ps[i]] = '+'; step(i + 1);
    expr[sign_ps[i]] = '-'; step(i + 1);
    expr[sign_ps[i]] = '*'; step(i + 1);
}

int main() {
    read();
    step();
    cout << -1;
}