/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0449 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int l, n; cin >> l >> n;
    vector<int> dt(n);
    for(auto &x: dt) cin >> x;
    sort(ALL(dt));
    vector<int> ans = {dt.front() + l};
    for (auto &c: dt) {
        if (abs(ans.back() - c) <= l) continue;
        ans.push_back(c + l);
    }
    cout << ans.size();
}