/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0996 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> usd;
    int ans = 1, n; cin >> n;
    for (int i = 2; i <= n; i++) {
        usd.insert(ans);
        if (usd.count(i)) ans += 3;
        else ans += 2;
    }
    cout << ans;
}