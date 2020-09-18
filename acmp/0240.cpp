#include<bits/stdc++.h>
using namespace std;

int n, f, y, i, p = '.', a, x, h;

struct Q {
    char dt[10][10][10] = {0}; // x // y // h
    Q(int k) { n = k; }
    
#define F ; for (y = 0; y < n; y++)  for (x = 0; x < n; x++) { for (h = 0; h < n; h++) {
    
    void r(int t = 0){
        char nx[10][10][10];
        memcpy(nx, dt, sizeof(nx))
        F
                    !t ? dt[n - h - 1][y][x] = nx[x][y][h]: dt[x][h][n - y - 1] = nx[x][y][h];
        }}
    }
    aply (deque<string> s) {
        a = 0
        F
                    if (s[y][x] != p)
                        if (!dt[x][y][h] || dt[x][y][h] == s[y][x]) {
                            dt[x][y][h] = s[y][x];
                            break;
                        }
                    a |= dt[x][y][h] != p;
                    dt[x][y][h] = p;
                }
            
        }
        return a;
    }

    cnt () {
        int a = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                for (int h = 0; h < n; h ++)
                    a += dt[i][j][h] != p;
        return a;
    }
};


main() {
    cin >> n;
    Q h(n);
    deque<string> s[6];
    for (y = 0; y < n; y++) {
        string c;
        for (i = 0; i < 6; i++) {
            cin >> c;
            s[i].push_front(c);
        }
    }
    f = 1;
    while(f) {
        f = 0;
        f |= h.aply(s[0]); h.r();
        f |= h.aply(s[1]); h.r();
        f |= h.aply(s[2]); h.r();
        f |= h.aply(s[3]); h.r();
        h.r(1); f |= h.aply(s[4]); h.r(1);
        h.r(1); f |= h.aply(s[5]); h.r(1);
    }
    cout << h.cnt();
}