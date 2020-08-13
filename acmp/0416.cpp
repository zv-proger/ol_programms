/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0416 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<char, char>;
pii operator + (pii a, pii b) { return {a.first + b.first, a.second + b.second}; }
vector<pii> sk = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

void make_ans(pii x) {
    if (x.first < 'a' || x.first > 'h' || x.second < '1' || x.second > '8') return;
    cout << x.first << x.second << endl;
}

int main() {
    pii a; cin >> a.first >> a.second;
    for (auto s: sk) {
        make_ans(s + a);
    }
}