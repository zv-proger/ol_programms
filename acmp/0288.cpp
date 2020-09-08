/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0288 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<string, pair<string, int>> to = {
    {"//", {"\n", 1}}, {"{", {"}", 1}}, {"(*", {"*)", 1}}, {"\'", {"\'", 0}}, {"", {"", 0}}
};

int main() {
    string s; getline(cin, s, '\0');
    int ans = 0;
    size_t f = 0;
    string st = "";
    do {
        ans += to[st].second;
        st = to[st].first;
        s.erase(0, f + st.length());
        f = s.find(st);
        s.erase(0, f + st.length());
        f = string::npos;
        for (auto &p: to) {
            if (p.first == "") continue;
            if (s.find(p.first) < f){
                f = s.find(p.first);
                st = p.first;
            }
        }
    } while (f != string::npos);
    cout << ans;
}