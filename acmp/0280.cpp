/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0280 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll x; cin >> x;
    map<ll, int> divs;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            divs[i--]++;
        }
    }
    ll ans = 1;
    for (auto &p: divs) ans *= p.second;
    cout << ans;
}