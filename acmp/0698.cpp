/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0698 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

char coz;

struct card {
    int m, v;
    void read() {
        char c; cin >> c;
        if (isdigit(c)) v = c - '0'; 
        else v = map<char, int>({{'T', 10},{'J', 11},{'Q', 12},{'K', 13},{'A', 14}}) [c];
        cin >> c;
        if (c == coz) m = 5;
        else m = map<char, int>({{'S', 1},{'C', 2},{'Q', 3},{'H', 4}})[c];
    }
    friend bool operator <(card a, card b) {
        return make_pair(a.m, a.v) < make_pair(b.m, b.v);
    }
    bool beat(card o) const {
        if (o.m == m) return v > o.v;
        if (m == 5) return true;
        return false;
    }
};

card readCard() {
    card x; x.read();
    return x;
}

int main() {
    int n, m; cin >> n >> m >> coz;
    set<card> st;
    for (; n--;) st.insert(readCard());
    for (; m--;) {
        card x; x.read();
        for (auto &a: st) {
            if (a.beat(x)) {
                st.erase(a); goto nxt;
            }
        }
        cout << "NO"; return 0;
        nxt:;
    }
    cout << "YES";
}