/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0522 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> a, b; int n, m; cin >> n >> m;
    for (; n-- ;) {
        int x; cin >> x; a.insert(x);
    }
    for (; m-- ;) {
        int x; cin >> x; b.insert(x);
    }
    cout << (a == b);
}