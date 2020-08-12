/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0594 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

int main() {
    pii dt[100000]; int n; cin >> n;
    map<string, int> mul = {
        {"m", 1}, {"km", 1000}, {"mile", 1609}, {"uin", 33},
        {"kairi", 1852}, {"zhang", 3}, {"sen", 38}
    };
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(ALL(s));
        int c = 0;
        while (isdigit(s.back())) {
            c = c * 10 + s.back() - '0';
            s.pop_back();
        }
        reverse(ALL(s));
        dt[i] = { c * mul[s], i + 1};
    }
    sort (dt, dt + n);
    int bst = n - 1; double v = 0;
    for(int r = 2; r < n; r++) {
        double a = dt[r].first, b = dt[r-1].first, c = dt[r-2].first, p = (a + b + c) / 2;
        if (a + 1e-6 > b + c) continue;
        double sqr = sqrt(p*(p-a)*(p-b)*(p-c));
        if (v < sqr) {bst = r; v = sqr;}
    }

    cout << fixed << setprecision(7) << v / 4 << endl;
    cout << dt[bst].second << ' ' << dt[bst - 1].second << ' ' << dt[bst - 2].second << ' ' << endl;
}