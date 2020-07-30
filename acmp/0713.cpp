/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0713 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bool f(const int &a, const int &b) {
    static string fs;
    if (fs.empty()) cin >> fs;
    return fs[b + 2 * a] == '1';
}

#define cnt first
#define pr second.first
#define val second.second

int main() {
    int n; cin >> n;
    vector<pair<int, pii>> dp[2];
    dp[0].assign(n - 1, {-1, {-1, 0}});
    dp[1].assign(n - 1, {-1, {-1, 0}});
    if (f(0,1)) { dp[0][0].cnt = 1; dp[0][0].val = 1; }
    else if (f(0,0)) { dp[0][0].cnt = 0; }
    if (f(1,1)) { dp[1][0].cnt = 1; dp[1][0].val = 1; }
    else if (f(1,0)) { dp[1][0].cnt = 0; }
    for (int i = 1; i < n - 1; i++) {
        if (dp[0][i-1].cnt >= 0) {
            if (!f(0,1) && dp[0][i-1].cnt + 1 > dp[0][i].cnt) { dp[0][i].cnt = dp[0][i-1].cnt + 1; dp[0][i].pr = 0; dp[0][i].val = 1; }
            if (!f(0,0) && dp[0][i-1].cnt     > dp[0][i].cnt) { dp[0][i].cnt = dp[0][i-1].cnt;     dp[0][i].pr = 0; dp[0][i].val = 0; }
            if (!f(1,1) && dp[0][i-1].cnt + 1 > dp[1][i].cnt) { dp[1][i].cnt = dp[0][i-1].cnt + 1; dp[1][i].pr = 0; dp[1][i].val = 1; }
            if (!f(1,0) && dp[0][i-1].cnt     > dp[1][i].cnt) { dp[1][i].cnt = dp[0][i-1].cnt;     dp[1][i].pr = 0; dp[1][i].val = 0; }
        }
        if (dp[1][i-1].cnt >= 0) {
            if ( f(0,1) && dp[1][i-1].cnt + 1 > dp[0][i].cnt) { dp[0][i].cnt = dp[1][i-1].cnt + 1; dp[0][i].pr = 1; dp[0][i].val = 1; }
            if ( f(0,0) && dp[1][i-1].cnt     > dp[0][i].cnt) { dp[0][i].cnt = dp[1][i-1].cnt;     dp[0][i].pr = 1; dp[0][i].val = 0; }
            if ( f(1,1) && dp[1][i-1].cnt + 1 > dp[1][i].cnt) { dp[1][i].cnt = dp[1][i-1].cnt + 1; dp[1][i].pr = 1; dp[1][i].val = 1; }
            if ( f(1,0) && dp[1][i-1].cnt     > dp[1][i].cnt) { dp[1][i].cnt = dp[1][i-1].cnt;     dp[1][i].pr = 1; dp[1][i].val = 0; }
        }
    }
    if (dp[0].back().cnt < 0 && dp[1].back().cnt < 0) doans("No solution");
    int cur = dp[1].back().cnt >= dp[0].back().cnt;
    string s = cur ? "1" : "0";
    for (;!dp[0].empty();) {
        s.push_back('0' + dp[cur].back().val);
        cur = dp[cur].back().pr;
        dp[0].pop_back();
        dp[1].pop_back();
    }
    doans(s);
}