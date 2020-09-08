cost = {}
for i in range(int(input())):
    a, b = input().split()
    cost[a] = int(b)
 
for i in range(int(input())):
    t, a = input().split()
    *a, = map(int, ''.join(c if c.isdigit() else ' ' for c in a).split())
    ans = cost[t]
    for i in a[::-1]:
        ans *= i
        ans += 24
    print(ans)