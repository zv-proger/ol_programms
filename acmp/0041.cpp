/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0041 с сайта acmp.ru
*/
     
#include<bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
 
const int inf = 1e9;
 
using ll = long long;
using pii = pair<int, int>;
 
int main() {
    FASTIO;
    int n; cin >> n;
    vector<int> a(n); for(int &x: a) cin >> x;
    sort(ALL(a));
    for(int &x: a) cout << x << ' ';
}