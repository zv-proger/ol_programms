/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0124 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> ans(n);
    for (m*=2; m--;) {
        int x; cin >> x;
        ans[x-1]++;
    }
    for (auto x : ans) cout << x << ' ';
}