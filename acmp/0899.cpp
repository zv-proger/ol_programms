/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0899 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<char, char> to = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

int calc(string s) {
    stack<char> st;
    for (auto &c: s) {
        if (to.count(c)) st.push(c);
        else {
            if (st.empty() || to[st.top()] != c) return 1;
            st.pop();
        }
    }
    return !st.empty();
}

int main() {
    for (string s; cin >> s;) {
        cout << calc(s);
    }
}