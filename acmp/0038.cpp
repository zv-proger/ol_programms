/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0038 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int sign(int a) { return a ? a > 0 ? 1 : 2 : 0; }

int main() {
    int n; cin >> n;
    vector<int> a(n); for(int &x: a) cin >> x;
    map<pii, int> dp;
    for (int i = 0; i < n; i++) 
        dp[{i,i}] = a[i];
    for (int l = 1; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            dp[{i, i + l}] = max(a[i] - dp[{i + 1, i + l}], a[i+l] - dp[{i, i + l - 1}]);
        }
    }
    cout << sign(dp[{0, n - 1}]) << endl;
}