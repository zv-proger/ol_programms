#import<iostream>

int p[99][99], a, b, c, d, i, q;

#define x std::cin >> a

main() {
    for(x; x >> c >> b >> d;)
        for(q = 0; a ^ b; a++)
            for(i = c > d? c^=d^=c^=d: c; i < d; )
                q += p[a > b? a^=b^=a^=b: a][i++]++;
    std::cout << q;

}