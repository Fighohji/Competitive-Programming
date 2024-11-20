import sys, os, io
from collections import defaultdict
from collections import deque
from types import GeneratorType
import math


def bootstrap(f, stack=[]):
    def wrapped(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrapped


input = sys.stdin.readline
print = sys.stdout.write


def qpow(base, power):
    res = 1
    while (power):
        if power & 1:
            res = res * base
        base = base * base
        power >>= 1
    return res


Ans = []


def solve():
    n = int(input())
    for i in range(3, 4):
        l = 2
        r = int(math.pow(10000000000000000000, 1 / (i - 1))) + 1
        while l <= r:
            mid = (l + r) // 2
            # print(str(mid))
            # print("\n")
            L = (qpow(mid, i) - 1) // (mid - 1)
            # print(str(L) + "\n")
            R = n
            if L == R:
                Ans.append("Yes")
                return
            elif L < R:
                l = mid + 1
            else:
                r = mid - 1
    Ans.append("No")


t = int(input())
while t > 0:
    t -= 1
    solve()
print("\n".join(Ans[::1]))