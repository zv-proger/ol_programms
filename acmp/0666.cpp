/*
    Àâòîğ êîäà: Âàäèì Çèíîâ (zv.proger@yandex.ru)
    Ğåøåíèå çàäà÷è 0666 ñ ñàéòà acmp.ru
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
    ll n, k = 1; read(n);
    char c = 'a';
    for (int i = 0; i < 26; i++) {
        c++;
        k = k * 2 + 1;
    }       
    for (;n;) {
        k /= 2;
        if (k < n) n -= k;
        n--;
        c--;
    }
    doans(c);
}