/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0744 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

void do_yes() {
    cout << "YES" << endl; exit(0);
}

map<char, char> to = {{'{', '}'},{'(', ')'},{'[', ']'}};

void check(const string &s) {
    stack<char> st;
    for (auto c: s) {
        if (to.count(c)) {
            st.push(c);
        } else {
            if (st.empty() || to[st.top()] != c) {
                return;
            }
            st.pop();
        }
    }
    if (st.empty()) do_yes();
}

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++) {
        check(s);
        s.push_back(s.front());
        s.erase(0, 1);
    }
    cout << "NO";
}