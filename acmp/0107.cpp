/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0107 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<string, int> cost = {
    {"aa", 2}, {"aba", 2}, {"aab", 2}, {"abb", 2}, {"aaa", 3},
    {"abac", 2}, {"abcb", 2}, {"abab", 3}, {"aabb", 3}, {"abba", 4},
    {"abbb", 3}, {"abaa", 3}, {"aaba", 3}, {"aaab", 3}, {"aaaa", 5},
};

int calc(string a) {
    map<char, char> x; char l = 'a';
    for (auto &c: a) {
        if (x.count(c)) c = x[c];
        else c = x[c] = l++;
    }
    if (cost.count(a)) return cost[a];
    return 0;
}

vector <int> ans = {2, 2, 3};
int bst = 0;

void check(vector<int> p, string s) {
    int cur = 0, l = 0;
    for (size_t i = 0; i < p.size(); i++) {
        cur += calc(s.substr(l, p[i]));
        l += p[i];
    }
    if (cur > bst) {
        ans = p;
        bst = cur;
    }
}

int main() {
    string s; cin >> s;
    check({4, 3}, s);
    check({3, 4}, s);
    check({2, 2, 3}, s);
    check({2, 3, 2}, s);
    check({3, 2, 2}, s);
    cout << s.substr(0, ans[0]);
    int l = ans[0];    
    for (size_t i = 1; i < ans.size(); i++) {
        cout << '-' << s.substr(l, ans[i]);
        l += ans[i];
    }
    cout << endl << bst;
}