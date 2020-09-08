p = [0] * 9 ** 6
a = 0
n = int(input()
while n:
    n -= 1
    t, s = map(int, input().split())
    while s * t:
        if p[t] < s:
            a += s
            p[t], s = s, p[t]
            a -= s
        t -= 1
print(a)