/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0901 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve_slow(int n) {
    vector<set<int>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].insert(i);
        for (int j = 1; j * 2 <= i; j++) {
            int f = *dp[i-j].rbegin();
            for (auto s: dp[j]) {
                dp[i].insert(lcm(f, s));
            }
            f = *dp[j].rbegin();
            for (auto s: dp[i-j]) {
                dp[i].insert(lcm(f, s));
            }
        }
    }
    cout << *dp.back().rbegin();
}

void make_calc() {
    int n = 60;
    vector<set<int>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].insert(i);
        for (int j = 1; j * 2 <= i; j++) {
            for (auto f: dp[j]) {
                for (auto s: dp[i-j]) {
                    dp[i].insert(lcm(f, s));
                }
            }
        }
    }
    cout << "cout << vector<int>({0, ";
    for (int i = 1; i < n; i++) {
        cout << *dp[i].rbegin() << ", ";
    }
    cout << *dp.back().rbegin() << "})[n];";
}


void solve_fast(int n) {
    cout << vector<int>({0, 1, 2, 3, 4, 6, 6, 12, 15, 20, 30, 30, 60, 60, 84, 105, 140, 210, 210, 420, 420, 420, 420, 840, 840, 1260, 1260, 1540, 2310, 2520, 4620, 4620, 5460, 5460, 9240, 9240, 13860, 13860, 16380, 16380, 27720, 30030, 32760, 60060, 60060, 60060, 60060, 120120, 120120, 180180, 180180, 180180, 180180, 360360, 360360, 360360, 360360, 471240, 510510, 556920, 1021020})[n];
}

int main() {
    int n; cin >> n;
    //make_calc();
    solve_slow(n); 
    //solve_fast(n);
}