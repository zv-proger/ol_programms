/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0589 с сайта acmp.ru
*/
#include<bits/stdc++.h>
using namespace std;

using cr_t = long double;
const cr_t eps = 1e-12;

struct vec_t {
    cr_t x, y, z;
    vec_t (cr_t a, cr_t b, cr_t c) { x = a, y = b, z = c; }
    vec_t (): vec_t({0,0,0}) {}
    cr_t len() const { return sqrt(x*x + y*y + z*z); }
};
inline vec_t operator + (vec_t a, vec_t b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
inline vec_t operator - (vec_t a, vec_t b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
inline vec_t operator / (vec_t a, cr_t d) { return {a.x / d, a.y / d, a.z / d}; }
inline vec_t operator * (vec_t a, cr_t d) { return {a.x * d, a.y * d, a.z * d}; }
inline ostream &operator << (ostream &o, vec_t a) { return o << fixed << setprecision(3) << a.x << ' ' << a.y << ' ' << a.z; }
inline istream &operator >> (istream &i, vec_t &a) { return i >> a.x >> a.y >> a.z; }

struct ball {
    vec_t pos, vec;
    cr_t r, m;
    inline ball after(cr_t t) {
        ball ans = *this;
        ans.pos = ans.pos + ans.vec * t;
        return ans;
    }
    void add_imp(vec_t imp) {
        vec = vec + imp / m;
    }
};
inline ostream &operator << (ostream &o, ball a) { return o << a.pos << ' ' << a.vec; }
inline istream &operator >> (istream &i, ball &a) { return i >> a.m >> a.r >> a.pos >> a.vec; }

inline cr_t dist_bw(ball a, ball b, cr_t t = 0) {
    return (a.after(t).pos - b.after(t).pos).len() - a.r - b.r;
}

inline cr_t collision_after(ball a, ball b){
    cr_t l = 0, r = 101;
    while (r - l > eps * 1000) {
        cr_t ml = (r - l) / 3 + l, mr = ml + (r - l) / 3;
        if (dist_bw(a, b, ml) > dist_bw(a, b, mr))
            l = ml;
        else
            r = mr;
    }
    if (dist_bw(a, b, l) > -eps) return -1;
    l = 0;
    while (abs(dist_bw(a, b, l)) > eps) {
        cr_t m = (l + r) / 2;
        if (dist_bw(a, b, m) < 0)
            r = m;
        else
            l = m;
    }
    return l;
}

inline cr_t e(vec_t p, cr_t m) {
    return (p.x * p.x + p.y * p.y + p.z * p.z) / 2 / m;
}

inline void do_collision(ball &a, ball &b) {
    vec_t pa = a.vec * a.m, pb = b.vec * b.m;
    cr_t E = e(pa, a.m) + e(pb, b.m);
    vec_t l = {0, 0, 0}, r = (a.pos - b.pos) / (a.pos - b.pos).len() * (pa.len() + pb.len()) * 1.7;
    while (max(abs(r.x - l.x), max(abs(r.y - l.y), abs(r.z - l.z))) > eps) {
        vec_t m = (l + r) / 2;
        if ((e(pa + m, a.m) + e(pb - m, b.m) - E) * (e(pa + r, a.m) + e(pb - r, b.m) - E) > 0)
            r = m;
        else
            l = m;
    }
    a.add_imp(l);
    b.add_imp(l * -1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin >> n;
    vector<ball> dt(n);
    for (auto &b: dt) cin >> b;
    cin >> t;

    using pdp = pair<cr_t, pair<int, int>>;
    priority_queue<pdp, vector<pdp>, greater<pdp>> q;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cr_t t = collision_after(dt[i], dt[j]);
            if (t > 0) q.push({t, {i, j}});
        }
    }
    cr_t pr = 0, cr = 0;
    for (; !q.empty(); pr = cr) {
        cr = q.top().first;
        int a = q.top().second.first, b = q.top().second.second;
        q.pop();
        if (cr > t + eps) break;
        for (auto &b: dt) b = b.after(cr - pr);
        if (dist_bw(dt[a], dt[b]) > eps) continue;
        do_collision(dt[a], dt[b]);
        for (int i = 0; i < n; i++) {
            if (i - a) {
                cr_t t = collision_after(dt[i], dt[a]);
                if (t > 0) q.push({cr + t, {i, a}});
            }
            if (i - b) {
                cr_t t = collision_after(dt[i], dt[b]);
                if (t > 0) q.push({cr + t, {i, b}});
            }
        }
    }
    for (auto &b: dt) cout << b.after(t - pr) << endl;
}