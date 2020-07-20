/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0154 � ����� acmp.ru

    �������� �� ����� ������ ����������� ����� � ������� �������������, ���� ������� � ����� ���� N
*/

#include<bits/stdc++.h>
using namespace std;

int mx = 1; // ������������ ����� ��� �������� �� ������ ��������
void init(int n) {
    for (int i = 1; 1LL * i*i*i <= n; i++) {
        mx = i;
    }
}

vector<int> ans;

void calc(int n) {
    if (n == 0) { for (auto x : ans) cout << x << ' '; exit(0); }
    if (ans.size() > 7) return;

     // ���������� ������������ ����� ��� �������� �� ������ n
    int l = 0, r = mx + 1;
    while(l < r -1) {
        int m = (l + r) / 2;
        if (m * m * m > n) {
            r = m;
        } else {
            l = m;
        }
    }

    for (int x = l; x > 0; x--) {
        int y = x*x*x;
        if (y > n) continue;
        ans.push_back(x);
        calc(n - y);
        ans.pop_back();
    }
}

int main() {
    ll n; cin >> n;
    init(n);
    calc(n);
    cout << "IMPOSSIBLE";
}