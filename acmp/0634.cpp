#include<bits/stdc++.h>
using namespace std;
 
 
int n, k, i, gr[9][9], t[9], j, a[9], c[9], b = 1e9, l, r;

main() {
    for (cin >> n >> k; i <= n; i++)
        for (j = -1; ++j < n; c[i] = i) cin >> (i - n ? gr[i][j]: t[j]);
 
    for( ; r |= next_permutation(c, c + n), r--; j < b ? memcpy(a, c, 4*k), b = j: 0)
        for (j = t[*c], i = 0; ++i < k; j += gr[c[i-1]][c[i]])
            j += t[c[i]];
     
    for (cout << b; l < k;)
        cout << ' ' << a[l++] + 1;
}