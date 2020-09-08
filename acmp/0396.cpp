/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0396 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<int, int> dt;

int main() {
    int n, m; cin >> n >> m;
    while (n--) {
        int a, b; cin >> a >> b;
        dt[min(a, b)]++; dt[max(a, b) + 1]--;
    }
    int cur = 0;
    for (auto &p: dt) {
        dt[p.first] = cur += p.second;
    }
    dt[-1e9] = 0;
    while (m--) {
        int a; cin >> a;
        cout << (--dt.upper_bound(a)) -> second << ' ';
    }
}