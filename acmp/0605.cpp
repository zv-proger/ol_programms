/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0605 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<pair<char, int>> cur;

void do_ans() {
    if (cur.back().first != 'D' && cur.back().first != 'X') return;
    ostringstream ss;
    for (auto &p: cur) {
        if (p.first == 'X') {
            ss << "Bull ";
            continue;
        }
        if (p.first != ' ') {
            ss << p.first;
        }
        ss << p.second << ' ';
    }
    ans.push_back(ss.str());
}

void step(int n, int cnt = 3) {
    if (n < 0) return;
    if (n == 0) do_ans();
    if (cnt == 0) return;
    for (int i = 1; i <= 20; i++) {
        cur.push_back({' ', i});
        step(n - i, cnt - 1);
        cur.pop_back();
        cur.push_back({'D', i});
        step(n - 2 * i, cnt - 1);
        cur.pop_back();
        cur.push_back({'T', i});
        step(n - 3 * i, cnt - 1);
        cur.pop_back();
    }
    cur.push_back({' ', 25});
    step(n - 25, cnt - 1);
    cur.pop_back();
    cur.push_back({'X', 0});
    step(n - 50, cnt - 1);
    cur.pop_back();
}

int main() {
    int n; cin >> n;
    step(n, 3);
    cout << ans.size() << endl;
    for (auto &s: ans) {
        cout << s << endl;
    }
}