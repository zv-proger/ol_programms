/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0498 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> dt;

bool check() {
    for (int i = 1; i < n; i++) {
        if (abs(dt[i]-dt[i-1]) > k)
            return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dt.push_back(i);
    }
    ans += check();
    for (; next_permutation(dt.begin(), dt.end());) {
        ans += check();
    }
    cout << ans;
}