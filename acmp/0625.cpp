/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 625 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<char, int> cnt;
map<char, set<char>> cmn;
set<char> sgn;

void read() {
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        if (!i) sgn = {s.begin(), s.end()};
        for (int i = 0; s[i]; i++) {
            cnt[s[i]] = i + 1;
            cmn[s[i]] = {s.begin(), s.end()};
        }
    }
    cnt[' '] = 1;
}

int caps_state = 2, ans;
char pr;

void add(char c) {
    if (sgn.count(c)) { if (!caps_state) caps_state = 2; goto end; }
    if (c == ' ') goto end;
    if (isupper(c)) { ans += !caps_state; caps_state = caps_state == 2? 0: 1; c = tolower(c); goto end; }
    if (islower(c)) { ans += !!caps_state; caps_state = 0; goto end; }

    end:
    ans += cmn[pr].count(c) + cnt[c];
    pr = c;
}

int main() {
    read();
    string s;
    getline(cin, s); getline(cin, s);;
    for (auto &c: s)  add(c);
    cout << ans << endl;
}