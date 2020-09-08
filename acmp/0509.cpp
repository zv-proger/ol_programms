/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0509 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct state {
    string pl[2];

    vector<state> nxt_states() const {
        vector<state> ans;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 4; j++) {
                if (pl[i][j] == '#') {
                    if (i) {
                        auto x = *this;
                        swap(x.pl[i-1][j], x.pl[i][j]);
                        ans.push_back(x);
                    }
                    if (j) {
                        auto x = *this;
                        swap(x.pl[i][j-1], x.pl[i][j]);
                        ans.push_back(x);
                    }
                    if (i < 1) {
                        auto x = *this;
                        swap(x.pl[i+1][j], x.pl[i][j]);
                        ans.push_back(x);
                    }
                    if (j < 3) {
                        auto x = *this;
                        swap(x.pl[i][j+1], x.pl[i][j]);
                        ans.push_back(x);
                    }
                }
            }
        }
        return ans;
    }

    friend bool operator <(const state &a, const state &b) {
        return make_pair(a.pl[0], a.pl[1]) < make_pair(b.pl[0], b.pl[1]);
    }

    void print() const {
        cout << pl[0] << endl << pl[1] << endl;
    }

    friend bool operator ==(const state &a, const state &b) {
        return make_pair(a.pl[0], a.pl[1]) == make_pair(b.pl[0], b.pl[1]);
    }
};

state readState() {
    state x; cin >> x.pl[0] >> x.pl[1];
    return x;
}

int main() {
    state s = readState(), e = readState(), l;
    set<state> usd;
    queue<state> q; q.push(s); q.push(l);
    usd.insert(s);
    int ans = 0;
    while (true) {
        auto cur = q.front(); q.pop();
        if (cur == l) {
            ans ++;
            if (q.empty()) { ans = -1; break; }
            q.push(l); continue;
        }
        if (cur == e) {
            break;
        }
        for (auto &nxt: cur.nxt_states()) {
            if (usd.count(nxt)) continue;
            usd.insert(nxt);
            q.push(nxt);
        }
    }
    cout << ans;
}