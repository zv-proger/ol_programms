/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи m с сайта codeforces.com
*/

#include<bits/stdc++.h>
using namespace std;

struct vec {
    int x, y, z;
    double len() const { return sqrt(x * x + y * y + z * z); }
};

vec operator- (vec a, vec b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

double cs_bw(vec a, vec b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z) / a.len() / b.len();
}

istream &operator >> (istream &i, vec &x) { return i >> x.x >> x.y >> x.z; }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
#ifndef LCL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(9);
    vec S, E, T;
    int r;
    cin >> S >> T >> r >> E;
    double cs = cs_bw(E-S, T-S);
    if (cs < 1e-20) {
        cout << "MISS" << endl;
        cout << (S-T).len();
        return 0;
    }
    double a = (E-S).len();
    double b = (S-T).len();
    double c = (T-E).len();
    double pp = (a + b + c) / 2;
    double s = sqrt((long double)pp*(pp-a)*(pp-b)*(pp-c));
    double d = 2 * s / a;
    cout << (d > r + 1e-9 ? "MISS": "HIT") << endl << d;
}