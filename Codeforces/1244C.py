x, y = 0, 0


def extend_gcd(a, b):
    global x
    global y
    if a == 0 and b == 0:
        return -1
    elif b == 0:
        x = 1
        y = 0
        return a
    res = extend_gcd(b, a % b)
    x, y = y, x
    y -= a // b * x
    return res


n, p, w, d = map(int, input().split())
g = extend_gcd(w, d)
if p % g != 0:
    print(-1)
else:
    w //= g
    d //= g
    p //= g
    x *= p
    y *= p
    ans = 1
    if x < 0:
        temp = (-x) // d
        if (-x) % d != 0:
            temp += 1
        x += temp * d
        y -= temp * w
        if y < 0:
            ans = -1
    elif y < 0:
        temp = (-y) // w
        if (-y) % w != 0:
            temp += 1
        x -= temp * d
        y += temp * w
        if x < 0:
            ans = -1
    if ans == -1:
        print(ans)
    else:
        if x + y <= n:
            print(x, y, n - x - y, sep=' ')
        else:
            temp = x + y
            cnt = (temp - n) // (w - d)
            if (temp - n) % (w - d) != 0:
                cnt += 1
            x += d * cnt
            y -= w * cnt
            if x > n or y < 0:
                print(-1)
            else:
                print(x, y, n - x - y, sep=' ')
