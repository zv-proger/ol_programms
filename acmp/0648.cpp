/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0648 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dt(n);
    for (auto &x: dt) cin >> x;
    sort(dt.begin(), dt.end());
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        ans += dt[r--] - dt[l++];
    }
    cout << ans;
}