/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0700 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, v, k; cin >> n >> v >> k;
    long long s = 0;
    for (; n-- && v > 0; v -= k) {
        s += v;
    }
    cout << (n < 0 ? "YES" : "NO") << ' ' << s;
}