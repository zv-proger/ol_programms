/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0442 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool is_tag = false;
    stack<int> st; st.push(10);
    map<int, int> a;
    while(1) {
        if (is_tag) {
            getline(cin, s, '>');
            if (s == "/font") st.pop();
            if (s.find("font size=\"") == 0) {
                int nh = 0, d;
                if (!isdigit(s[11])) nh = st.top();
                istringstream(s.substr(11, s.length() - 12)) >> d;
                st.push(d + nh);
            }
        } else {
            getline(cin, s, '<');
            if (!cin) break;
            for (auto &c: s) if (!isspace(c)) a[st.top()]++;
        }
        is_tag = !is_tag;
    }
    for (auto &p: a) cout << p.first << ' ' << p.second << endl;
}