/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0444 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dt[1000];

string f(int l, int r) {
    stringstream ss;
    ss << l;
    for (int i = l + 1; i <= r; i++) {
        ss << ", " << i;
    }
    return ss.str();
}
string s(int l, int r) {
    if (r - l < 2) return f(l, r);
    stringstream ss;
    ss << l << ", ..., " << r;
    return ss.str();
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> dt[i];
    sort(dt, dt + n);
    int l, r = 0;
    string ans;
    do {
        l = r++;
        while (r < n && (dt[r-1] == dt[r] || dt[r-1] == dt[r] - 1)) r++;
        string a = f(dt[l], dt[r-1]), b = s(dt[l], dt[r-1]);
        if (a.length() > b.length()) a = b;
        ans += (ans == "" ? "" : ", ") + a;
    } while (r < n);
    cout << ans;
}