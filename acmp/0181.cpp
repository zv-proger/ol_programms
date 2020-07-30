/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0181 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;
map<char, string> cmd;
string s = "NSWEUD";
int dp['Z'][101] = {0};

int calc(const char &c,const int &n) {
    if (!n || !cmd.count(c)) return 0;
    if (dp[c][n]) return dp[c][n];
    for (auto &x : cmd[c]) {
        dp[c][n] += calc(x, n-1);
    }
    return ++dp[c][n];
}

int main() {
    for (auto &c : s) {
        getline(cin, cmd[c]);
    }
    char start; cin >> start; int count; cin >> count;
    cout << calc(start, count);
}