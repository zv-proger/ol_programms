/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0739 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int k; string s; cin >> k >> s;
    map<char, queue<int>> pos;
    for (int i = 0; i < k; i++) {
        pos[s[i]].push(i);
    }
    string ans;
    for (int i = 0; ans.length() < s.length(); i++) {
        if (i + k < s.length()) {
            pos[s[i + k]].push(i + k);
        }
        for (auto &p: pos) {
            if (!p.second.empty() && p.second.front() == i - k) {
                p.second.pop();
                ans += p.first;
                goto nxt;
            }
        }
        for (auto &p: pos) {
            if (!p.second.empty()) {
                p.second.pop();
                ans += p.first;
                goto nxt;
            }
        } nxt:;
    }
    cout << ans;
}