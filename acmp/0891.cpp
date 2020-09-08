/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0891 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

enum view_id {
    vid_front,
    vid_left,
    vid_back,
    vid_right,
    vid_top,
    vid_bottom
};

enum vec_id {
    vec_left,
    vec_right,
    vec_up,
    vec_down,
    vec_clockwise,
    vec_contrclockwise
};

void memswap(void *a, void *b, size_t cnt) {
    static int buff[1000];
    memcpy(buff, a, cnt);
    memcpy(a, b, cnt);
    memcpy(b, buff, cnt);
}

template<int N = 3> struct rub_cube_t {
    char dt[6][N][N]; // v, x, y

    rub_cube_t() { memset(dt, '#', sizeof(dt)); }

    int hash() {
        int ans = 0, sk = 31, md = 100000007;
        for (int v = 0; v < 6; v++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    ans = (1LL + ans * sk + dt[v][x][y] - 'A') % md;
                    ans %= md;
                }
            }
        }
        return ans;
    }

    bool bad() {
        return ***dt == '#';
    }

    bool check() {
        for (int v = 0; v < 6; v++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    if (dt[v][x][y] != dt[v][0][0]) return false;
                }
            }
        }
        return true;
    }

    void _rot(view_id v, vec_id d) {
        assert(d == vec_clockwise || d == vec_contrclockwise);
        char bk[N][N];
        memcpy(bk, dt[v], sizeof(bk));
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                switch (d) {
                    case vec_clockwise: dt[v][y][N-x-1] = bk[x][y]; break;
                    case vec_contrclockwise: dt[v][N-y-1][x] = bk[x][y]; break;
                    default: ;
                }
            }
        }
    }

    void _swap(view_id v1, view_id v2) {
        memswap(dt[v1], dt[v2], N*N);
    }

    void rot(vec_id d) {
        switch (d) {
            case vec_left:
                _swap(vid_front, vid_left);
                _swap(vid_left, vid_back);
                _swap(vid_back, vid_right);
                _rot(vid_top, vec_contrclockwise);
                _rot(vid_bottom, vec_clockwise);
                break;
            case vec_right:
                _swap(vid_front, vid_right);
                _swap(vid_right, vid_back);
                _swap(vid_back, vid_left);
                _rot(vid_top, vec_clockwise);
                _rot(vid_bottom, vec_contrclockwise);
                break;
            case vec_up:
                _swap(vid_front, vid_top);
                _swap(vid_top, vid_back);
                _swap(vid_back, vid_bottom);
                _rot(vid_left, vec_clockwise);
                _rot(vid_right, vec_contrclockwise);
                _rot(vid_top, vec_clockwise);
                _rot(vid_top, vec_clockwise);
                _rot(vid_back, vec_clockwise);
                _rot(vid_back, vec_clockwise);
                break;
            case vec_down:;
                _swap(vid_front, vid_bottom);
                _swap(vid_bottom, vid_back);
                _swap(vid_back, vid_top);
                _rot(vid_left, vec_contrclockwise);
                _rot(vid_right, vec_clockwise);
                _rot(vid_bottom, vec_clockwise);
                _rot(vid_bottom, vec_clockwise);
                _rot(vid_back, vec_clockwise);
                _rot(vid_back, vec_clockwise);
                break;
            case vec_clockwise:;
                _swap(vid_left, vid_bottom);
                _swap(vid_bottom, vid_right);
                _swap(vid_right, vid_top);
                _rot(vid_front, vec_clockwise);
                _rot(vid_back, vec_contrclockwise);
                _rot(vid_left, vec_clockwise);
                _rot(vid_top, vec_clockwise);
                _rot(vid_right, vec_clockwise);
                _rot(vid_bottom, vec_clockwise);
                break;
            case vec_contrclockwise:;
                _swap(vid_left, vid_top);
                _swap(vid_top, vid_right);
                _swap(vid_right, vid_bottom);
                _rot(vid_front, vec_contrclockwise);
                _rot(vid_back, vec_clockwise);
                _rot(vid_left, vec_contrclockwise);
                _rot(vid_top, vec_contrclockwise);
                _rot(vid_right, vec_contrclockwise);
                _rot(vid_bottom, vec_contrclockwise);
                break;
        }
    }


    void write() {
        for (int y = N; y--; ) {
            for (int v = 0; v < 6; v++) {
                for (int x = 0; x < N; x++) {
                    cout << dt[v][x][y];
                }
                cout << ' ';
            }
            cout << endl;
        }
    }

    void read() {
        string s;
        for (int y = N; y--; ) {
            for (int v = 0; v < 6; v++) {
                cin >> s;
                for (int x = 0; x < N; x++) {
                    dt[v][x][y] = s[x];
                }
            }
        }
    }

    void _shift(vec_id d, int z) {
        assert(d == vec_clockwise || d == vec_contrclockwise);
        if (!z) _rot(vid_front, d);
        if (z == N-1) _rot(vid_back, d != vec_clockwise ? vec_clockwise: vec_contrclockwise);
        _rot(vid_bottom, vec_contrclockwise);
        _rot(vid_top, vec_clockwise);
        _rot(vid_left, vec_clockwise);
        _rot(vid_left, vec_clockwise);

        switch(d) {
            case vec_clockwise:
                memswap(dt[vid_top][z], dt[vid_left][z], N);
                memswap(dt[vid_left][z], dt[vid_bottom][z], N);
                memswap(dt[vid_bottom][z], dt[vid_right][z], N);
                break;
            case vec_contrclockwise:
                memswap(dt[vid_top][z], dt[vid_right][z], N);
                memswap(dt[vid_right][z], dt[vid_bottom][z], N);
                memswap(dt[vid_bottom][z], dt[vid_left][z], N);
                break;
                default:;
        }

        _rot(vid_left, vec_clockwise);
        _rot(vid_left, vec_clockwise);
        _rot(vid_top, vec_contrclockwise);
        _rot(vid_bottom, vec_clockwise);
    }

    void shift(vec_id d, int depth, view_id v = vid_front) {
        assert(depth >= 0 && depth < N);
        switch(v) {
            case vid_front:     _shift(d, depth); break;
            case vid_left:  rot(vec_left); _shift(d, depth); rot(vec_right); break;
            case vid_back: rot(vec_left); rot(vec_left); _shift(d, depth); rot(vec_right); rot(vec_right); break;
            case vid_right: rot(vec_right); _shift(d, depth); rot(vec_left); break;
            case vid_top: rot(vec_up); _shift(d, depth); rot(vec_down); break;
            case vid_bottom: rot(vec_down); _shift(d, depth); rot(vec_up); break;
        }
    }
};
const int CUR_X = 3;
using rub_cube2_t = rub_cube_t<2>;
using rub_cube3_t = rub_cube_t<3>;
using rub_cube4_t = rub_cube_t<4>;
using rub_cubex_t = rub_cube_t<CUR_X>;

unordered_map<int, pair<int, pair<char, char>>> par;

void par_update(rub_cubex_t &a, long long p, pair<char, char> e) {
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_left);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_left);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_left);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_right);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_right);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_contrclockwise);
    par[a.hash()] = {p, e}; a.rot(vec_right);
}


int main() {
    int n; cin >> n;
    cout << sizeof(pair<char, char>);
    assert(n == CUR_X);
    rub_cubex_t x, y;
    x.read();
    if (x.check()) {
        cout << "Solved"; return 0;
    }
    queue<rub_cubex_t> q; q.push(x); q.push(y);
    par_update(x, 0, {'x', 0});
    int s = x.hash(), e;
    int step = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.bad()) {
            step++; cout << step << "   " << fixed << setprecision(3) << clock() / CLOCKS_PER_SEC / 60 << "m. " << 1. * (clock() % (3600 * CLOCKS_PER_SEC)) / CLOCKS_PER_SEC << "s." << endl;
            if (q.empty()) break;
            q.push(cur); continue;
        }
        int ch = cur.hash();
        for (int i = 0; i < n; i++) {
            #define R(wc) \
            if (!par.count(cur.hash())) { \
                q.push(cur); \
                par_update(cur, ch, {wc, i+1}); \
                if (cur.check()) { \
                    e = cur.hash(); \
                    break; \
                } \
            }
            #define _(wh, wc) \
            cur.shift(vec_clockwise, i, wh); R(tolower(wc)); cur.shift(vec_contrclockwise, i, wh); \
            cur.shift(vec_contrclockwise, i, wh); R(toupper(wc)); cur.shift(vec_clockwise, i, wh); \

            _(vid_front, 'F');
            _(vid_right, 'R');
            _(vid_top, 'U');
        }
    }
    list<pair<char, char>> ans;
    while (e != s) {
        ans.push_front(par[e].second);
        e = par[e].first;
    }
    for (auto &p: ans) {
        cout << p.first << +p.second  << endl;
    }
}