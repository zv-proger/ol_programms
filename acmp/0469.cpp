/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0469 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dt(n); for (int &i : dt) cin >> i;
    dt.push_back(dt[0]);
    dt.push_back(dt[1]);
    int ans = 0;
    for (int i = 2; i < n + 2; i++) {
        ans = max(ans, dt[i-2] + dt[i-1] + dt[i]);
    }
    cout << ans;
}