/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0760 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, v, l; cin >> n >> v >> l;
    double ans = l * 1.0 * 60 / v;
    for (; n--;) {
        int t, x; cin >> x >> t;
        if (x < l) ans += t;
    }
    cout << fixed << setprecision(2) << ans;
}