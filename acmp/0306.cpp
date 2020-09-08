/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0306 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

string f(int x, bool b = true) {
    char cur = 'B', prev = 'R';
    string ans;
    for (int i = 0; i < x; i++) {
        ans += cur; swap(cur, prev);
    }
    return ans;
}

int main() {
    int x; cin >> x;
    list<char> ans;
    auto s = f(x);
    ans.push_back(s.back()); s.pop_back();
    while (!s.empty()) {
        ans.push_front(ans.back());
        ans.pop_back();
        ans.push_front(s.back());
        s.pop_back();
    }
    for (auto &x: ans) cout << x;
}