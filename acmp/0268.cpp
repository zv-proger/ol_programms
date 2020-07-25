/*
    Àâòîğ êîäà: Âàäèì Çèíîâ (zv.proger@yandex.ru)
    Ğåøåíèå çàäà÷è 0268 ñ ñàéòà acmp.ru
*/
     
#include<bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
const int inf = 1e9;
 
using ll = long long;
using pii = pair<int, int>;
 
void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
 
 
int main() {
    int n, k; string s; read(n, k, s);
    int dp1[5001] = {0}, dp2[5001] = {0}, *cur = dp2, *prev = dp1;
    int ans = n;
    for (int l = 0; l < n; l++) {
        prev[l] = k;
        if (l) {
            cur[l-1] = k - (s[l] != s[l-1]);
            ans += cur[l-1] >= 0;           
        }
    }
    for (int l = 2; l < n; l++) {
        swap(cur, prev);
        for (int i = 0; l + i < n; i++) {
            cur[i] = cur[i+1] - (s[i] != s[i+l]);
            ans += cur[i] >= 0;
        }
    }
    doans(ans);
}